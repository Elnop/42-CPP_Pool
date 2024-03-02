#include <iomanip>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

bool file_to_db(std::map<std::string, float> &db) {
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "can't open ./data.csv\n";
		return false;
	}
	for (std::string row; file; std::getline(file, row))
	{
		std::string date_str = row.substr(0, row.find(","));
		if (date_str.empty() || date_str == "date")
			continue ;
		std::string count_str = row.substr(row.find(",")+1, row.length()-1);
		float count = atof(count_str.c_str());
		db[date_str] = count;
	}
	return true;
}

void do_queries(const char *filename, std::map<std::string, float> &db) {
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return ;
	}
	for (std::string row; file; std::getline(file, row))
	{
		if (row.find(" ") == std::string::npos)
			continue ;
		std::string date_str = row.substr(0, row.find(" "));
		if (date_str.empty() ||  date_str == "date")
			continue ;
		std::string count_str = row.substr(row.find(" | ")+3, row.length()-1);
		if (date_str.empty() || count_str.empty())
		{
			std::cerr << "Error: invalid row";
			continue ;
		}
		// CHECK DATE
		if(date_str < "2001-42-42")
		{
			std::cerr << "Error: bad input => 2001-42-42\n";
			continue ;
		}
		// CHECK COUNT
		float count = atof(count_str.c_str());
		if (count > 1000)
		{
			std::cerr << "Error: too large a number.\n";
			continue;
		}
		if (count < 0)
		{
			std::cerr << "Error: too low a number.\n";
			continue;
		}
		std::string	date_max = date_str;
		float	price;	
		for (std::map<std::string, float>::iterator it = db.begin(); it != db.end() && it->first <= date_max; it++)
			price=it->second;
		float result = price * count;
		std::cout << date_str << " => " << std::setprecision(2) << count << " = " << result << std::endl;
	}
}

int main(int argc, const char** argv)
{
	(void)argv;
	if (argc < 2)
	{
		std::cerr << "./btc <filename>\n";
		return 1;
	}
	std::map<std::string, float> db;
	// map<date, count>
	if(!file_to_db(db))
		return 1;
	do_queries(argv[1], db);
	return 0;
}