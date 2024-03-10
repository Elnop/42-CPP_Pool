#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &copy) : _N(copy._N), _vec(copy._vec) {}

Span &Span::operator=(const Span &copy) {
	if (this != &copy) {
		_N = copy._N;
		_vec = copy._vec;
	}
	return *this;
}

Span::~Span() {}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	int shortest = _N;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++) {
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

void Span::addNumber(int n) {
	if (_vec.size() == _N)
		throw FullException();
	_vec.push_back(n);
}

void Span::addNumberRange(unsigned int n) {
	for (unsigned int i = 0; i < n; i++)
		this->addNumber(i);
}