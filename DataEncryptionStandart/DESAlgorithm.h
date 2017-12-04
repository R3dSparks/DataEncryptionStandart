#pragma once

enum CipherMode
{
	ECM,
	CBC,
	CFB,
	OFB
};

class DESAlgorithm
{
public:
	static void Encrypt(long*, int, long, CipherMode);
	static void Decrypt(long*, int, long, CipherMode);

private:
	DESAlgorithm();
	~DESAlgorithm();
};




