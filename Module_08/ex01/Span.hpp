#include <vector>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _vec;
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();
		void addNumber(int n);
		void addNumberRange(unsigned int n);
		int shortestSpan();
		int longestSpan();
		class FullException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Span is full");
				}
		};
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Not enough numbers");
				}
		};

};