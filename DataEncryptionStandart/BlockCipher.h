#pragma once
#include "EncryptionAlgorithm.h"

enum CipherMode
{
	ECM, // Electronic codebook mode
	CBC, // Cypher-Block chaining mode
	CFB, // Cypher feedback mode
	OFB	 // Output feedback mode
};

typedef unsigned long long uint64_t;

class BlockCipher
{

public:
	static void Encrypt(uint64_t*, int, CipherMode, EncryptionAlgorithm);
	static void Decrypt(uint64_t*, int, CipherMode, EncryptionAlgorithm);

private:
	BlockCipher();
	~BlockCipher();

	static void ecmEncrypt(uint64_t*, int, EncryptionAlgorithm);
};

