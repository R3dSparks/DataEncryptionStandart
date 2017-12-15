#include "DESAlgorithm.h"


DESAlgorithm::DESAlgorithm(uint64_t _key)
{
	this->key_ = _key;
	this->encryption_round_key_ = KeyGenerator(_key);
}


DESAlgorithm::~DESAlgorithm()
{
	delete(encryption_round_key_);
}

// Public

uint64_t DESAlgorithm::Encrypt(uint64_t _message)
{
	_message = Permutations::Permutate(_message, 64, 64, IP);

	unsigned int left = _message >> 32;
	unsigned int right = _message & 0xffffffff;
	uint64_t expanded_right = 0;

	for (int i = 0; i < 16; i++)
	{
		expanded_right = Permutations::Permutate(right, 32, 48, E);

		expanded_right ^= this->encryption_round_key_[i];

		expanded_right = Permutations::SBoxSubstitution(expanded_right);

		expanded_right = Permutations::Permutate(expanded_right, 32, 32, P);
	
		expanded_right ^= left;

		left = right;

		right = expanded_right;

	}

	_message = ((uint64_t)right << 32) | ((uint64_t)left);

	return Permutations::Permutate(_message, 64, 64, PI);
}

uint64_t DESAlgorithm::Decrypt(uint64_t _cyphertext)
{
	_cyphertext = Permutations::Permutate(_cyphertext, 64, 64, IP);

	unsigned int left = _cyphertext >> 32;
	unsigned int right = _cyphertext & 0xffffffff;

	for (int i = 0; i < 16; i++)
	{
		uint64_t expanded_right = Permutations::Permutate(right, 32, 48, E);

		expanded_right ^= this->encryption_round_key_[15 - i];

		expanded_right = Permutations::SBoxSubstitution(expanded_right);

		expanded_right ^= left;

		left = right;

		right = Permutations::Permutate(expanded_right, 32, 32, P);
	}

	_cyphertext = ((uint64_t)right << 32) | ((uint64_t)left);

	return Permutations::Permutate(_cyphertext, 64, 64, PI);
}

uint64_t* DESAlgorithm::KeyGenerator(uint64_t _key)
{
	uint64_t* keys = new uint64_t[16];

	_key = Permutations::Permutate(_key, 64, 56, PC1);

	uint64_t left = _key >> 28;
	uint64_t right = _key & 0xfffffff;

	uint64_t round_key = 0;

	for (int i = 0; i < 16; i++)
	{
		int rotation = (i == 0 || i == 1 || i == 8 || i == 15) ? 1 : 2;

		left = rotateLeft(left, 28, rotation);
		right = rotateLeft(right, 28, rotation);

		round_key = right | (left << 28);

		keys[i] = Permutations::Permutate(round_key, 56, 48, PC2);
	}

	return keys;
}

// Private

uint64_t DESAlgorithm::rotateLeft(uint64_t _value, int _range, int _steps)
{
	if (_range > 64)
		throw "Range can only be between 0 and 64";

	if (_steps > _range)
		throw "Steps can't be larger than range";

	uint64_t buffer = _value >> (_range - _steps);

	return ((_value << _steps) | buffer) & (0xffffffffffffffff >> (64 - _range));
}

uint64_t DESAlgorithm::rotateRight(uint64_t _value, int _range, int _steps)
{
	if (_range > 64)
		throw "Range can only be between 0 and 64";

	if (_steps > _range)
		throw "Steps can't be larger than range";

	uint64_t buffer = _value & (0xffffffffffffffff >> (64 - _steps));

	return (_value >> _steps) | (buffer << (_range - _steps));
}