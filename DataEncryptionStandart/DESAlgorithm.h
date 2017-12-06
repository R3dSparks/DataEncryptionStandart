#pragma once
#include "BlockCipher.h"
#include "Permutations.h"

class DESAlgorithm
{
public:
	DESAlgorithm(long);
	~DESAlgorithm();

	long Encrypt(long);
	long Decrypt(long);

	static long* KeyGenerator(long);

private:
	long key_;
	long* round_key_;

	static long rotateLeft(long, int, int);
};




