#pragma once
#include <math.h>

#define IP Permutations::InputPermutation
#define PI Permutations::OutputPermutation

typedef int perm_64[64];

class Permutations
{
public:
	static int* Permutate(const int*, const perm_64);

	// Input permutation table
	static const perm_64 InputPermutation;

	// Output permutation table
	static const perm_64 OutputPermutation;

private:
	Permutations();
	~Permutations();

};

