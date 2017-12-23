#pragma once

typedef unsigned long long uint64_t;

class EncryptionAlgorithm
{
public:
	EncryptionAlgorithm();
	~EncryptionAlgorithm();

	virtual uint64_t Encrypt(uint64_t);
};

