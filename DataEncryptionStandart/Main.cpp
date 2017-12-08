#include <iostream>
#include <bitset>

#include "BlockCipher.h"
#include "DESAlgorithm.h"
#include "Permutations.h"

int main()
{
	DESAlgorithm desa = DESAlgorithm(0x1);

	uint64_t cypher = desa.Encrypt(0x31);

	std::cout << std::hex << cypher << std::endl;

	uint64_t message = desa.Decrypt(cypher);

	std::cout << std::hex << message << std::endl;

	std::getchar();
}