#include <iostream>
#include <stack>

int main (int ac, const char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./RPN \"<Reverse Polish Notation>\"" << std::endl;
        return 1;
    }
    std::stack<double> queue = std::stack<double>();
    // for (char arg : std::string(av[1])) C++11 i miss you </3
    for (unsigned long i=0; av[1][i]; i++)
    {
        char arg = av[1][i];
        if (arg == ' ')
            continue;
        if (arg >= '0' && arg <= '9')
        {
            queue.push(arg - '0');
            continue;
        }
        if (queue.size() < 2)
        {
            std::cerr << "Error : number needed" << std::endl;
            return 1;
        }
        double a = queue.top();
        queue.pop();
        double b = queue.top();
        queue.pop();
        switch (arg)
        {
            case '+':
                queue.push(a + b);
                break;
            case '-':
                queue.push(b - a);
                break;
            case '*':
                queue.push(a * b);
                break;
            case '/':
                queue.push(b / a);
                break;
            default:
                std::cerr << "Error : invlid character" << std::endl;
                return 1;
        }
    }
    if (queue.size() != 1)
    {
        std::cerr << "Invalid RPN" << std::endl;
        return 1;
    }
    std::cout << queue.top() << std::endl;
}