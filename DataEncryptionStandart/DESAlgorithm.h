#pragma once
#include "BlockCipher.h"

class DESAlgorithm
{
public:
	static void Encrypt(long*, int, long, CipherMode);
	static void Decrypt(long*, int, long, CipherMode);

private:
	DESAlgorithm();
	~DESAlgorithm();
};




