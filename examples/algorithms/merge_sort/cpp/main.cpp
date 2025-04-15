#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


template<class Container>
void print_values(const Container &container, const std::string &type_name)
{
	std::cout << "Printing type : " << type_name << std::endl;
	for(auto it = container.begin(); it != container.end(); it++)
	{
		if(it  != container.begin())
		{
			std::cout << ", ";
		}
		std::cout << (*it);
	}
	std::cout << std::endl;
}

template<class Container>
void print_keys_and_values(const Container &container, const std::string &type_name)
{
	std::cout << "Printing type : " << type_name << std::endl;
	for(auto it = container.begin(); it != container.end(); it++)
	{
		if(it  != container.begin())
		{
			std::cout << ", ";
		}
		std::cout << (*it.first) << ":" << (*it.second);
	}
	std::cout << std::endl;
}

template<class V>
void merge(V &vec, const int begin, const int middle,  const int end)
{
	const int vec_size = (end - begin) + 1;
	V tmp_vec(vec.begin() + begin, vec.begin() + end + 1);

	const int vec1_end = middle;
	const int vec2_end = end;
	int vec1_current = begin;
	int vec2_current = (middle+1);
	int new_index = 0;
	for(new_index = begin; new_index <= end; new_index++)
	{
		if(vec2_current > end)
		{
			vec[new_index] = tmp_vec[vec1_current - begin];
			vec1_current++;
		}
		else if(vec1_current > middle)
		{
			vec[new_index] = tmp_vec[vec2_current - begin];
			vec2_current++;
		}
		else if(tmp_vec[vec1_current - begin] < tmp_vec[vec2_current - begin])
		{
			vec[new_index] = tmp_vec[vec1_current - begin];
			vec1_current++;
		}
		else
		{
			vec[new_index] = tmp_vec[vec2_current - begin];
			vec2_current++;
		}
	}
}

template<class V>
void merge_sort(V &vec, const int begin,  const int end)
{
	if(begin >= end)
	{
		return;
	}

	const int middle = (begin+end) / 2;

	merge_sort(vec, begin, middle);
	merge_sort(vec, middle+1, end);

	merge(vec, begin, middle, end);
}

int main(const int argc, const char *argv[])
{
	int status = 0;
	
	std::ifstream file("program_files/unsorted_numbers.csv");
    	std::string str;
    	while (std::getline(file, str))
    	{
		std::vector<int> number_vec;

		std::istringstream f(str);
		std::string str_num;
    		while (std::getline(f, str_num, ',')) {
			int num = 0;

  			try {
    				num = std::stoi(str_num);
  			} catch (const std::invalid_argument& e) {
    				std::cerr << "Invalid argument: " << e.what() << std::endl;
  			} catch (const std::out_of_range& e) {
    				std::cerr << "Out of range: " << e.what() << std::endl;
  			}

			number_vec.push_back(num);
    		}

		print_values(number_vec, "before");

		merge_sort(number_vec, 0, number_vec.size() - 1);

		print_values(number_vec, "after");
	}

	std::cout << "done" << std::endl;
	
	return status;
}
