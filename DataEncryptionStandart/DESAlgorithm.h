#pragma once
#include "BlockCipher.h"
#include "Permutations.h"

class DESAlgorithm
{
public:
	DESAlgorithm(uint64_t);
	~DESAlgorithm();

	uint64_t Encrypt(uint64_t);
	uint64_t Decrypt(uint64_t);

	static uint64_t* EncryptKeyGenerator(uint64_t);
	static uint64_t* DecryptKeyGenerator(uint64_t);

private:
	uint64_t key_;
	uint64_t* encryption_round_key_;
	uint64_t* decryption_round_key_;

	static uint64_t rotateLeft(uint64_t, int, int);
	static uint64_t rotateRight(uint64_t, int, int);
};




