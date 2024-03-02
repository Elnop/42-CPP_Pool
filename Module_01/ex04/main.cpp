#include <cstddef>
#include <ios>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac < 4)
	{
		std::cerr << "./Sed_is_for_losers <filename> <s1> <s2>\n";
		return 1;
	}

	std::ifstream infileStream(av[1]);

	std::string s1 = av[2];
	std::string s2 = av[3];

	std::string outfileName = av[1];
	outfileName += ".replace";
	std::ofstream outfileStream;
	outfileStream.open(outfileName.c_str(), std::ios::out);

	std::string	inLine;
	std::size_t found;
	while (getline(infileStream, inLine)) {
		std::string	outLine;
		found = inLine.find(av[2]);
		if (found == std::string::npos)
		{
			outfileStream << inLine + "\n";
			continue ;
		}
		size_t currPos = 0;
		while (found != std::string::npos)
		{
			outLine += inLine.substr(currPos, found - currPos);
			outLine += s2;
			currPos = found + s1.length();
			found = inLine.find(av[2], currPos);
		}
		outfileStream << outLine << inLine.substr(currPos) << "\n";
	}
}
