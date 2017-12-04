#include "BlockCipher.h"



BlockCipher::BlockCipher()
{
}


BlockCipher::~BlockCipher()
{
}

void BlockCipher::Encrypt(long* _message, int _blocks, long _key, CipherMode _mode, EncryptionAlgorithm _encrypt)
{
	switch (_mode)
	{
	case ECM:
		ecmEncrypt(_message, _blocks, _key, _encrypt);
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

void BlockCipher::Decrypt(long* _cyphertext, int _blocks, long _key, CipherMode _mode, EncryptionAlgorithm _encrypt)
{
}

// Private

void BlockCipher::ecmEncrypt(long* _message, int _blocks, long _key, EncryptionAlgorithm _encrypt)
{
	for (int i = 0; i < _blocks; i++)
		_message[i] = _encrypt(_message[i], _key);
}
