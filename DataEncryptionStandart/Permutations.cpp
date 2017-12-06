#include "Permutations.h"


Permutations::Permutations()
{
}


Permutations::~Permutations()
{
}

const perm Permutations::InputPermutation =
{
	39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24
};

const perm Permutations::OutputPermutation =
{
	57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7,
	56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 
	60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6
};

const perm Permutations::Permutation =
{
	15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9,
	1, 7, 23, 13, 31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24
};

const perm Permutations::Extension = 
{

};

const perm Permutations::KeyPermutation1 = 
{
	56, 48, 40, 32, 24, 16, 8, 0,
	57, 49, 41, 33, 25, 17, 9, 1,
	58, 50, 42, 34, 26, 18, 10, 2,
	59, 51, 43, 35, 27, 19, 11, 3,
	60, 52, 44, 36, 28, 20, 12, 4,
	61, 53, 45, 37, 29, 21, 13, 5,
	62, 54, 46, 38, 30, 22, 14, 6,
	63, 55, 47, 39, 31, 23, 15, 7
};

const perm Permutations::KeyPermutation2 =
{
	13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 21, 9,
	22, 18,	11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 
	40, 51, 30, 36,	46, 54, 29, 39, 50, 44,	32, 47,
	43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31
};

const sbox Permutations::SBox7 =
{

};

long Permutations::Permutate(long _value, int _output_length, const perm _permutationTable)
{
	long perm_value;

	for (int i = 0; i < _output_length; i++)
		setBit(perm_value, i, _value & (0x01 << _permutationTable[i]));

	return perm_value;
}

int Permutations::SBoxSubstitution(long _value)
{
	int result = 0;
	int s_round = 0;

	for (int i = 0; i < 8; i++)
	{
		s_round = (_value >> (i * 6)) & 0x3f;

		switch (i)
		{
		case 0:
			s_round = sBox(s_round, SBOX7);
			break;
		case 1:
			s_round = sBox(s_round, SBOX6);
			break;
		case 2:
			s_round = sBox(s_round, SBOX5);
			break;
		case 3:
			s_round = sBox(s_round, SBOX4);
			break;
		case 4:
			s_round = sBox(s_round, SBOX3);
			break;
		case 5:
			s_round = sBox(s_round, SBOX2);
			break;
		case 6:
			s_round = sBox(s_round, SBOX1);
			break;
		case 7:
			s_round = sBox(s_round, SBOX0);
			break;
		default:
			break;
		}

		result |= s_round << (i * 6);
	}

	return result;
}

int Permutations::sBox(int _value, const sbox _sbox)
{
	// Get the inner 4 bits of the input value
	int inner = (_value & 0x1e) >> 1;

	// Get the outer 2 bits of the input value
	int outer = (_value & 0x20) >> 4 + _value & 0x01;

	return _sbox[inner][outer];
}

void Permutations::setBit(long& _number, int _pos, bool _value)
{
	if (_value == true)
	{
		_number = _number | (0x01l << _pos);
	}
	else
	{
		_number = _number & !(0x01l << _pos);
	}
}