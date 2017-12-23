#include <iostream>
#include <bitset>

#include "BlockCipher.h"
#include "DESAlgorithm.h"
#include "Permutations.h"

int main()
{
	uint64_t message[] = { 0x123456789abcdef };

	DESAlgorithm des = DESAlgorithm(0x133457799BBCDFF1);

	BlockCipher::Encrypt(message, 1, CipherMode::ECM, des);

	std::cout << std::hex << message[0] << std::endl;

	std::getchar();
}