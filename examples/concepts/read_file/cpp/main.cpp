#include <fstream>
#include <iostream>

int main(const int argc, const char *argv[])
{
	int status = 0;
	
	std::ifstream file("program_files/unsorted_numbers.csv");
    	std::string str;
    	while (std::getline(file, str))
    	{
		std::cout << str << std::endl;
	}
	
	return status;
}
