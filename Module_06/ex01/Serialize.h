#include <stdint.h>

struct Data {
	int key;
	int value;
};

class Serialize {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		virtual ~Serialize() = 0;
};