#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>

template<typename Container>
bool has_duplicates(const Container& container) {
    typedef typename Container::value_type ValueType;
    typedef typename Container::const_iterator Iterator;

    std::vector<ValueType> temp(container.begin(), container.end());
    std::sort(temp.begin(), temp.end());
    
    Iterator it = std::unique(temp.begin(), temp.end());
    return it != temp.end();
}

bool is_number(const char* str) {
    while (*str != '\0' && std::isdigit(*str))
        ++str;
    return (*str == '\0');
}

std::vector<int> generate_vector(char **av) {
    std::vector<int> v;
    for (int i = 1; av[i]; i++) {
        if (!is_number(av[i])) {
            std::cerr << "Invalid input" << std::endl;
            exit(1);
        }
        v.push_back(atoi(av[i]));
    }
    return v;
}

std::deque<int> generate_deque(char **av) {
    std::deque<int> v;
    for (int i = 1; av[i]; i++) {
        if (!is_number(av[i])) {
            std::cerr << "Invalid input" << std::endl;
            exit(1);
        }
        v.push_back(atoi(av[i]));
    }
    return v;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " 1 3 2 ..." << std::endl;
        return 1;
    }
    std::vector<int> v = generate_vector(av);
    if (has_duplicates(v)) {
        std::cerr << "has duplicates" << std::endl;
        return 1;
    }
    PmergeMe< std::vector<int> >::sort_and_print(v);
    std::cout << std::endl;
    std::deque<int> l = generate_deque(av);
    PmergeMe< std::deque<int> >::sort_and_print(l);
    return 0;
}