#include "Permutations.h"


Permutations::Permutations()
{
}


Permutations::~Permutations()
{
}

const perm_64 Permutations::InputPermutation =
{
	39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24
};

const perm_64 Permutations::OutputPermutation =
{
	57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7,
	56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 
	60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6
};

const perm_64 Permutations::KeyPermutation1 = 
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

const perm_56 Permutations::KeyPermutation2 =
{
	13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 21, 9,
	22, 18,	11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 
	40, 51, 30, 36,	46, 54, 29, 39, 50, 44,	32, 47,
	43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31
};


int* Permutations::Permutate(const int* _value, int _output_length, const perm_64 _permutationTable)
{
	int* perm_value = new int[_output_length];

	for (int i = 0; i < _output_length; i++)
		perm_value[i] = _value[_permutationTable[i]];

	return perm_value;
}