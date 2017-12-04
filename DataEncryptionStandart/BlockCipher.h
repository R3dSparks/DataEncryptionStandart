#pragma once

enum CipherMode
{
	ECM, // Electronic codebook mode
	CBC, // Cypher-Block chaining mode
	CFB, // Cypher feedback mode
	OFB	 // Output feedback mode
};

typedef long (*EncryptionAlgorithm)(long, long);

class BlockCipher
{

public:
	static void Encrypt(long*, int, long, CipherMode, EncryptionAlgorithm);
	static void Decrypt(long*, int, long, CipherMode, EncryptionAlgorithm);

private:
	BlockCipher();
	~BlockCipher();

	static void ecmEncrypt(long*, int, long, EncryptionAlgorithm);
};

