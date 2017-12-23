#include "BlockCipher.h"



BlockCipher::BlockCipher()
{
}


BlockCipher::~BlockCipher()
{
}

void BlockCipher::Encrypt(uint64_t* _message, int _blocks, CipherMode _mode, EncryptionAlgorithm _algo)
{
	switch (_mode)
	{
	case ECM:
		ecmEncrypt(_message, _blocks, _algo);
	case CBC:
		break;
	case CFB:
		break;
	case OFB:
		break;
	default:
		break;
	}
}

void BlockCipher::Decrypt(uint64_t* _cyphertext, int _blocks, CipherMode _mode, EncryptionAlgorithm _algo)
{
}

// Private

void BlockCipher::ecmEncrypt(uint64_t* _message, int _blocks, EncryptionAlgorithm _algo)
{
	for (int i = 0; i < _blocks; i++)
		_message[i] = _algo.Encrypt(_message[i]);
}
