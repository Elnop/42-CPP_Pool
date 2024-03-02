#include <stack>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return *this;
		};
		~MutantStack() {};
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() { return std::stack<T, Container>::c.begin(); };
		iterator end() { return std::stack<T, Container>::c.end(); };
};
