#include "Serialize.h"
#include <stdint.h>
#include <iostream>
int main(void)
{
	// Serialize serialize;
	// (void)serialize;
	struct Data data = { 42, 8 };
	uintptr_t data_ptr = Serialize::serialize(&data);
	std::cout << "Data pointer: " << data_ptr << std::endl;
	Data* data2 = Serialize::deserialize(data_ptr);
	std::cout << "Data key: " << data2->key << "Value: " << data2->value << std::endl;
	return 0;
}