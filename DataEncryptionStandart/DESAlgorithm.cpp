#include "DESAlgorithm.h"


DESAlgorithm::DESAlgorithm(long _key)
{
	this->key_ = _key;
	this->round_key_ = KeyGenerator(_key);
}


DESAlgorithm::~DESAlgorithm()
{
	delete(round_key_);
}

// Public

long DESAlgorithm::Encrypt(long _message)
{
	_message = Permutations::Permutate(_message, 64, IP);

	int left = _message >> 32;
	int right = _message & 0xffffffff;

	for (int i = 0; i < 16; i++)
	{
		long expanded_right = Permutations::Permutate(right, 48, E);

		expanded_right ^= this->round_key_[i];


	}

	return Permutations::Permutate(_message, 64, PI);
}

long DESAlgorithm::Decrypt(long _cyphertext)
{
}

long* DESAlgorithm::KeyGenerator(long _key)
{
	long* keys = new long[16];

	_key = Permutations::Permutate(_key, 56, PC1);

	int left = _key >> 28;
	int right = _key & 0xfffffff;

	long round_key = 0;

	for (int i = 0; i < 16; i++)
	{
		int rotation = (i == 1 || i == 2 || i == 9 || i == 16) ? 1 : 2;

		left = (int)rotateLeft(left, 28, rotation);
		right = (int)rotateLeft(right, 28, rotation);

		round_key = right | (left << 28);

		keys[i] = Permutations::Permutate(round_key, 48, PC2);
	}

	return keys;
}

// Private

long DESAlgorithm::rotateLeft(long _value, int _range, int _steps)
{
	if (_range > 64)
		throw "Range can only be between 0 and 64";

	if (_steps > _range)
		throw "Steps can't be larger than range";

	long buffer = _value >> (_range - _steps);

	return (_value << _steps) | buffer;
}
