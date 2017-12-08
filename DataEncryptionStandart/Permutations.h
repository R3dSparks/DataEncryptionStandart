#pragma once
#include <math.h>

#define IP Permutations::InputPermutation
#define PI Permutations::OutputPermutation
#define P Permutations::Permutation
#define E Permutations::Extension
#define PC1 Permutations::KeyPermutation1
#define PC2 Permutations::KeyPermutation2
#define SBOX0 Permutations::SBox0
#define SBOX1 Permutations::SBox1
#define SBOX2 Permutations::SBox2
#define SBOX3 Permutations::SBox3
#define SBOX4 Permutations::SBox4
#define SBOX5 Permutations::SBox5
#define SBOX6 Permutations::SBox6
#define SBOX7 Permutations::SBox7

typedef int perm[];
typedef int sbox[4][16];
typedef unsigned long long uint64_t;

class Permutations
{
public:
	static uint64_t Permutate(uint64_t, int, const perm);
	static int SBoxSubstitution(uint64_t);

	// Input permutation table
	static const perm InputPermutation;

	// Output permutation table
	static const perm OutputPermutation;

	static const perm Permutation;

	static const perm Extension;

	static const perm KeyPermutation1;

	static const perm KeyPermutation2;

	static const sbox SBox0;
	static const sbox SBox1;
	static const sbox SBox2;
	static const sbox SBox3;
	static const sbox SBox4;
	static const sbox SBox5;
	static const sbox SBox6;
	static const sbox SBox7;


private:
	Permutations();
	~Permutations();

	static void setBit(uint64_t&, int, bool);
	static int sBox(int, const sbox);
};

