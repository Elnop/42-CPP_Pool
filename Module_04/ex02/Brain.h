#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
	protected:
		std::string* ideas[100];
	public:
		Brain();
		Brain(const Brain& rhs);
		Brain& operator=(const Brain& rhs);
		~Brain();
};

#endif