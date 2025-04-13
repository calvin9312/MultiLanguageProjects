#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>


template<class Container>
void print_container(const Container &container, const std::string &type_name)
{
	std::cout << "Printing type : " << type_name << std::endl;
	for(auto it = container.begin; it != container.end(); it++)
	{
		std::cout << (*it);
	}
}

int main(const int argc, const char *argv[])
{
	int status = 0;
	
	std::vector<std::vector<int> > number_vecs;

	std::ifstream file("program_files/unsorted_numbers.csv");
    	std::string str;
    	while (std::getline(file, str))
    	{
		std::map<int, int> number_map;
		std::set<int> number_set;
		std::vector<int> number_vec;
		std::stack<int> number_stack;
		std::deque<int> number_deque_forward;
		std::deque<int> number_deque_backward;
		std::queue<int> number_queue;
		std::priority_queue<int> number_priority_queue;

		std::istringstream f(str);
		std::string str_num;
    		while (std::getline(f, str_num, ',')) {
			int num = 0;

  			try {
    				num = std::stoi(str_num);
    				std::cout << "The integer value is: " << num << std::endl;
  			} catch (const std::invalid_argument& e) {
    				std::cerr << "Invalid argument: " << e.what() << std::endl;
  			} catch (const std::out_of_range& e) {
    				std::cerr << "Out of range: " << e.what() << std::endl;
  			}

			std::cout << num << std::endl;
			number_vec.push_back(num);
			number_set.insert(num);
			number_map[num] = num;
			number_stack.push_back(num);
			number_deque_forward.push_back(num);
			number_deque_backward.push_front(num);
			number_queue.push(num);
			number_priority_queue.push(num);
    		}
		number_vecs.push_back(number_vec);
	}

	std::cout << "done" << std::endl;
	
	return status;
}
