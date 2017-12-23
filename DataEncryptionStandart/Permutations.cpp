#include "Permutations.h"


Permutations::Permutations()
{
}


Permutations::~Permutations()
{
}

const perm Permutations::InputPermutation =
{
	57, 49, 41, 33, 25, 17, 9, 1, 
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7,
	56, 48, 40, 32, 24, 16, 8, 0,
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6
};

const perm Permutations::OutputPermutation =
{
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25,
	32, 0, 40, 8, 48, 16, 56, 24
};

const perm Permutations::Permutation =
{
	15, 6, 19, 20,
	28, 11, 27, 16, 
	0, 14, 22, 25,
	4, 17, 30, 9,
	1, 7, 23, 13,
	31, 26, 2, 8,
	18, 12, 29, 5,
	21, 10, 3, 24
};

const perm Permutations::Extension = 
{
	31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15, 16,
	15, 16, 17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23, 24, 25, 26, 27, 28, 27, 28, 29, 30, 31
};

const perm Permutations::KeyPermutation1 = 
{
	56, 48, 40, 32, 24, 16, 8, 0,
	57, 49, 41, 33, 25, 17, 9, 1,
	58, 50, 42, 34, 26, 18, 10, 2,
	59, 51, 43, 35, 62, 54, 46, 38,
	30, 22, 14, 6, 61, 53, 45, 37, 
	29, 21, 13, 5, 60, 52, 44, 36, 
	28, 20, 12, 4, 27, 19, 11, 3
};

const perm Permutations::KeyPermutation2 =
{
	13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9,
	22, 18,	11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 
	40, 51, 30, 36,	46, 54, 29, 39, 50, 44,	32, 47,
	43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31
};

#pragma region SBox


const sbox Permutations::SBox0 =
{
	{ 0xe, 4, 0xd, 1, 2, 0xf, 0xb, 8, 3, 0xa, 6, 0xc, 5, 9, 0, 7 },
	{ 0, 0xf, 7, 4, 0xe, 2, 0xd, 1, 0xa, 6, 0xc, 0xb, 9, 5, 3, 8 },
	{ 4, 1, 0xe, 8, 0xd, 6, 2, 0xb, 0xf, 0xc, 9, 7, 3, 0xa, 5, 0 },
	{ 0xf, 0xc, 8, 2, 4, 9, 1, 7, 5, 0xb, 3, 0xe, 0xa, 0, 6, 0xd }
};

const sbox Permutations::SBox1 =
{
	{0xf, 1, 8, 0xe, 6, 0xb, 3, 4, 9, 7, 2, 0xd, 0xc, 0, 5, 0xa},
	{3, 0xd, 4, 7, 0xf, 2, 8, 0xe, 0xc, 0, 1, 0xa, 6, 9, 0xb, 5},
	{0, 0xe, 7, 0xb, 0xa, 4, 0xd, 1, 5, 8, 0xc, 6, 9, 3, 2, 0xf},
	{0xd, 8, 0xa, 1, 3, 0xf, 4, 2, 0xb, 6, 7, 0xc, 0, 5, 0xe, 9}
};

const sbox Permutations::SBox2 =
{
	{0xa, 0, 9, 0xe, 6, 3, 0xf, 5, 1, 0xd, 0xc, 7, 0xb, 4, 2, 8},
	{0xd, 7, 0, 9, 3, 4, 6, 0xa, 2, 8, 5, 0xe, 0xc, 0xb, 0xf, 1},
	{0xd, 6, 4, 9, 8, 0xf, 3, 0, 0xb, 1, 2, 0xc, 5, 0xa, 0xe, 7},
	{1, 0xa, 0xd, 0, 6, 9, 8, 7, 4, 0xf, 0xe, 3, 0xb, 5, 2, 0xc}
};

const sbox Permutations::SBox3 =
{
	{7, 0xd, 0xe, 3, 0, 6, 9, 0xa, 1, 2, 8, 5, 0xb, 0xc, 4, 0xf},
	{0xd, 8, 0xb, 5, 6, 0xf, 0, 3, 4, 7, 2, 0xc, 1, 0xa, 0xe, 9},
	{0xa, 6, 9, 0, 0xc, 0xb, 7, 0xd, 0xf, 1, 3, 0xe, 5, 2, 8, 4},
	{3, 0xf, 0, 6, 0xa, 1, 0xd, 8, 9, 4, 5, 0xb, 0xc, 7, 2, 0xe}
};

const sbox Permutations::SBox4 =
{
	{2, 0xc, 4, 1, 7, 0xa, 0xb, 6, 8, 5, 3, 0xf, 0xd, 0, 0xe, 9},
	{0xe, 0xb, 2, 0xc, 4, 7, 0xd, 1, 5, 0, 0xf, 0xa, 3, 9, 8, 6},
	{4, 2, 1, 0xb, 0xa, 0xd, 7, 8, 0xf, 9, 0xc, 5, 6, 3, 0, 0xe},
	{0xb, 8, 0xc, 7, 1, 0xe, 2, 0xd, 6, 0xf, 0, 9, 0xa, 4, 5, 3}
};

const sbox Permutations::SBox5 =
{
	{0xc, 1, 0xa, 0xf, 9, 2, 6, 8, 0, 0xd, 3, 4, 0xe, 7, 5, 0xb},
	{0xa, 0xf, 4, 2, 7, 0xc, 9, 5, 6, 1, 0xd, 0xe, 0, 0xb, 3, 8},
	{9, 0xe, 0xf, 5, 2, 8, 0xc, 3, 7, 0, 4, 0xa, 1, 0xd, 0xb, 6},
	{4, 3, 2, 0xc, 9, 5, 0xf, 0xa, 0xb, 0xe, 1, 7, 6, 0, 8, 0xd}
};

const sbox Permutations::SBox6 =
{
	{4, 0xb, 2, 0xe, 0xf, 0, 8, 0xd, 3, 0xc, 9, 7, 5, 0xa, 6, 1},
	{0xd, 0, 0xb, 7, 4, 9, 1, 0xa, 0xe, 3, 5, 0xc, 2, 0xf, 8, 6},
	{1, 4, 0xb, 0xd, 0xc, 3, 7, 0xe, 0xa, 0xf, 6, 8, 0, 5, 9, 2},
	{6, 0xb, 0xd, 8, 1, 4, 0xa, 7, 9, 5, 0, 0xf, 0xe, 2, 3, 0xc}
};

const sbox Permutations::SBox7 =
{
	{0xd, 2, 8, 4, 6, 0xf, 0xb, 1, 0xa, 9, 3, 0xe, 5, 0, 0xc, 7},
	{1, 0xf, 0xd, 8, 0xa, 3, 7, 4, 0xc, 5, 6, 0xb, 0, 0xe, 9, 2},
	{7, 0xb, 4, 1, 9, 0xc, 0xe, 2, 0, 6, 0xa, 0xd, 0xf, 3, 5, 8},
	{2, 1, 0xe, 7, 4, 0xa, 8, 0xd, 0xf, 0xc, 9, 0, 3, 5, 6, 0xb}
};


#pragma endregion

uint64_t Permutations::Permutate(uint64_t _value, int input_length, int _output_length, const perm _permutationTable)
{
	uint64_t perm_value = 0;

	for (int i = 0; i < _output_length; i++)
	{
		setBit(perm_value, _output_length - i - 1, _value & (((uint64_t)0x01 << (input_length - 1)) >> _permutationTable[i]));
	}

	return perm_value;
}

uint64_t Permutations::SBoxSubstitution(uint64_t _value)
{
	uint64_t result = 0;
	unsigned int s_round = 0;

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

		result |= s_round << (i * 4);
	}

	return result;
}

unsigned int Permutations::sBox(unsigned int _value, const sbox _sbox)
{
	// Get the inner 4 bits of the input value
	int inner = (_value & 0x1e) >> 1;

	// Get the outer 2 bits of the input value
	int outer = ((_value & 0x20) >> 4) + (_value & 0x01);

	return _sbox[outer][inner];
}

void Permutations::setBit(uint64_t& _number, int _pos, bool _value)
{
	if (_value == true)
	{
		_number = _number | ((uint64_t)0x01 << _pos);
	}
	else
	{
		_number = _number & ~((uint64_t)0x01 << _pos);
	}
}