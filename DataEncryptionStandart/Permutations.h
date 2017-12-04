#pragma once
#include <math.h>

#define IP Permutations::InputPermutation
#define PI Permutations::OutputPermutation
#define PC1 Permutations::KeyPermutation1
#define PC2 Permutations::KeyPermutation2

typedef int perm_64[64];
typedef int perm_56[56];

class Permutations
{
public:
	static int* Permutate(const int*, int, const perm_64);

	// Input permutation table
	static const perm_64 InputPermutation;

	// Output permutation table
	static const perm_64 OutputPermutation;

	static const perm_64 KeyPermutation1;

	static const perm_56 KeyPermutation2;

private:
	Permutations();
	~Permutations();

};

