#if VERSION==0


#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <memory>

#include <time.h>

#if STL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	
	
	
#endif

template<class T>
void output_my_s(ft::stack<int, T> &t)
{
	ft::stack<int> buff;
	std::cout << "______My stack______" << std::endl;

	while (!t.empty())
	{
		buff.push(t.top());
		std::cout << t.top() << std::endl;
		t.pop();
	}
	while (!buff.empty())
	{
		t.push(buff.top());
		buff.pop();
	}
}

void output_v(ft::vector<int> &test)
{
	ft::vector<int>::iterator begin;
	ft::vector<int>::iterator end;

	begin = test.begin();
	end = test.end();

	std::cout << "My vector contains :" << std::endl;
	while (begin != end)
	{
		std::cout << "My vector |" << *begin <<  "|" << std::endl;
		begin++;
	}
}


void reverse_output_v(ft::vector<int> &test)
{
	ft::vector<int>::reverse_iterator rbegin;
	ft::vector<int>::reverse_iterator rend;

	rbegin = test.rbegin();
	rend = test.rend();

	while (rbegin != rend)
	{
		std::cout << *rbegin << std::endl;
		rbegin++;
	}
}

void output_my_map(ft::map<const std::string, int, std::less<const std::string>, std::allocator<ft::pair<const std::string, int> > > &a)
{	
	ft::map<const std::string, int, std::less<const std::string>, std::allocator<ft::pair<const std::string, int> > >::iterator begin = a.begin();
	ft::map<const std::string, int, std::less<const std::string>, std::allocator<ft::pair<const std::string, int> > >::iterator end = a.end();
	
	std::cout << "Map is :" << std::endl;
	while (begin != end)
	{
		std::cout <<  "keys :" << "|" << ((*begin).first) << "|"  << "		values : |" << ((*begin).second) << "|" << std::endl;
		++begin;
	}
}



int main()
{
	// if (STL)
	// 	std::cout << "_____________________RUNNING STL_____________________" << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
	// else
	// 	std::cout << "_____________________RUNNING MINE_____________________" << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
struct timeval time;
	gettimeofday(&time, NULL); // Start Time
	unsigned long long totalTime = (time.tv_sec * 1000) + (time.tv_usec/1000);


	std::cout << "________________VECTOR________________" << std::endl;
	
	{
		std::cout << "_____default constructor_____" << std::endl;
		ft::vector<int> test;
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____allocator constructor_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____fill constructor_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____range constructor_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		ft::vector<int> test1(test.begin(), test.begin() + 5, a);
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____copy constructor_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		ft::vector<int> test1(test);
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____operator =_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		ft::vector<int> test1;
		test1 = test;
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____assign count and values_____" << std::endl;
		ft::vector<int> test1;
		test1.assign(10, 100);
		output_v(test1);
		std::cout << std::endl;

	}

	{
		std::cout << "_____assign range_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		ft::vector<int> test1;
		test1.assign(test.begin(), test.begin() + 5);
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____get_allocator()_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(10, 100, a);
		ft::vector<int> test1(10, 100, test.get_allocator());
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____at_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "at index 3 : " << test.at(3) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____operator []_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "test[3] : " << test[3] << std::endl;
		std::cout << std::endl;
	}
	
	{
		std::cout << "_____front_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "front : " << test.front() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____back_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "back : " << test.back() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____data_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "data : " << test.data()[0] << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____begin_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "begin : " << *(test.begin()) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____const begin_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::const_iterator it = test.begin();
		std::cout << "const begin : " << *it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____end_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::const_iterator it = test.end();
		std::cout << "end : " << *--it << std::endl;
		std::cout << std::endl;
	}	
	{
		std::cout << "_____const end_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::const_iterator it = test.end();
		std::cout << "const end : " << *--it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____rbegin_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::reverse_iterator it = test.rbegin();
		std::cout << "rbegin : " << *it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____const rbegin_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::const_reverse_iterator it = test.rbegin();
		std::cout << "const rbegin : " << *it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____rend_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::reverse_iterator it = test.rend();
		std::cout << "rend : " << *--it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____const rend_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		ft::vector<int>::const_reverse_iterator it = test.rend();
		std::cout << "const rend : " << *--it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____empty_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		ft::vector<int> test1;
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "empty test :" << test.empty() << std::endl;
		std::cout << "empty test1 :" << test1.empty() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____size_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		std::cout << "size : " << test.size() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____max_size_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		std::cout << "max_size : " << test.max_size() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____reserve() and capacity_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.reserve(100);
		std::cout << "capacity : " << test.capacity() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____clear_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		test.clear();
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____insert single element_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.insert(test.begin(), 5);
		test.insert(test.begin(), 6);
		test.insert(test.begin(), 7);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____insert n elements with value value_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.insert(test.begin(), 5, 10);
		output_v(test);
		std::cout << std::endl;
	}


	{
		std::cout << "_____insert elements based on iterator range_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		ft::vector<int> test1;
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		test1.insert(test1.begin(), test.begin(), test.end());
		output_v(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____erase element in position_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		test.erase(test.begin() + 2);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____erase elements based on range_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		test.erase(test.begin(), test.begin() + 2);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____push_back_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);

		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____pop_back_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.pop_back();
		test.pop_back();
		output_v(test);
		std::cout << std::endl;
	}
	
	{
		std::cout << "_____resize bigger_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		test.resize(20);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____resize smaller_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);
		test.push_back(6);
		test.push_back(7);
		test.push_back(8);
		test.push_back(9);
		test.resize(4);
		output_v(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____ft::swap / swap and iterators_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);

		ft::vector<int> test1(a);
		test1.push_back(3);
		test1.push_back(2);
		test1.push_back(1);
		test1.push_back(0);

		ft::vector<int>::iterator it = test.begin();
		std::cout << "Before swap : " << std::endl;
		output_v(test);
		output_v(test1);
		ft::swap(test, test1);
		std::cout << "After swap : " << std::endl;
		output_v(test);
		output_v(test1);
		while (it != test1.end())
		{
			std::cout << "Iterators : " << *it << std::endl;
			it++;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "_____comparison operators_____" << std::endl;
		std::allocator<int> a;
		ft::vector<int> test(a);
		test.push_back(0);
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);

		ft::vector<int> test1(a);
		test1.push_back(7);
		test1.push_back(8);
		test1.push_back(3);
		test1.push_back(2);
		test1.push_back(1);
		test1.push_back(0);

		std::cout << "> : " << (test > test1) << std::endl;
		std::cout << ">= : " << (test >= test1) << std::endl;
		std::cout << "< : " << (test < test1) << std::endl;
		std::cout << "<= : " << (test <= test1) << std::endl;
		std::cout << "== : " << (test == test1) << std::endl;
		std::cout << "!= : " << (test != test1) << std::endl;
		std::cout << std::endl;
	}


	std::cout << "________________STACK________________" << std::endl;

{
	std::cout << "_____default constructor_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test;
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____underlying container constructor_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____copy constructor_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	ft::stack<int, ft::vector<int> > test1(test);
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____operator =_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	ft::stack<int, ft::vector<int> > test1;
	test1 = test;
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____top_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	std::cout << "top : " << test.top() << std::endl;
	std::cout << std::endl;
}

{
	std::cout << "_____empty_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	std::cout << "empty : " << test.empty() << std::endl;
	std::cout << std::endl;
}

{
	std::cout << "_____size_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	std::cout << "size : " << test.size() << std::endl;
	std::cout << std::endl;
}

{
	std::cout << "_____push_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____pop_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);
	test.pop();
	test.pop();
	output_my_s(test);
	std::cout << std::endl;
}

{
	std::cout << "_____comparison operators_____" << std::endl;
	ft::vector<int> a;
	ft::stack<int, ft::vector<int> > test(a);
	test.push(0);
	test.push(1);
	test.push(2);
	test.push(3);

	ft::stack<int, ft::vector<int> > test1(a);
	test1.push(7);
	test1.push(8);
	test1.push(3);
	test1.push(2);
	test1.push(1);
	test1.push(0);

	std::cout << "> : " << (test > test1) << std::endl;
	std::cout << ">= : " << (test >= test1) << std::endl;
	std::cout << "< : " << (test < test1) << std::endl;
	std::cout << "<= : " << (test <= test1) << std::endl;
	std::cout << "== : " << (test == test1) << std::endl;
	std::cout << "!= : " << (test != test1) << std::endl;
	std::cout << std::endl;
}
	std::cout << "________________PAIR________________" << std::endl;

	ft::pair<int, int> test(10, 10);
	ft::pair<int, int> test1;
	test1 = test;
	ft::pair<int, int> test2(test1);
	std::cout << test1.first << " " << test1.second << std::endl;
	std::cout << test2.first << " " << test2.second << std::endl;
	ft::pair<int, int> pairtest = ft::make_pair(100 , 1000);
	std::pair<int, int> real = std::make_pair(100, 1000);

	ft::pair<int, int> pairtest1 = ft::make_pair(100 , 1000);
	std::pair<int, int> real1 = std::make_pair(100, 1000);

	std::cout << "Comparison operators for pair test > test1 " << (pairtest > pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real > real1 " << (real > real1) << std::endl;

	std::cout << "Comparison operators for pair test < test1 " << (pairtest < pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real < real1 " << (real < real1) << std::endl;

	std::cout << "Comparison operators for pair test >= test1 " << (pairtest >= pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real >= real1 " << (real >= real1) << std::endl;

	std::cout << "Comparison operators for pair test <= test1 " << (pairtest <= pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real <= real1 " << (real <= real1) << std::endl;

	std::cout << "Comparison operators for pair test == test1 " << (pairtest == pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real == real1 " << (real == real1) << std::endl;

	std::cout << "Comparison operators for pair test != test1 " << (pairtest != pairtest1) << std::endl;
	std::cout << "Comparison operators for pair real != real1 " << (real != real1) << std::endl;


	std::cout << "________________MAP________________" << std::endl;
	typedef ft::map<const std::string, int, std::less<const std::string>, std::allocator<ft::pair<const std::string, int> > > map;
	{
		std::cout << "_____default constructor_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		map test;
		test.insert(ft::make_pair("Hello", 10));
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____compare and allocator constructor_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____iterator range constructor_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map test1(test.begin(), test.end());
		output_my_map(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____copy constructor_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map test1(test);
		output_my_map(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____operator =_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map test1;
		test1 = test;
		output_my_map(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____get_allocator_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << std::boolalpha;
		std::cout << "equal allocators : " << (a == test.get_allocator()) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____get_allocator_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << std::boolalpha;
		std::cout << "equal allocators : " << (a == test.get_allocator()) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____at_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test.at("Ola") = 9;
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____operator []_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test[("Ola")] = 9;
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____begin_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "begin : " << test.begin()->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____begin_const_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::const_iterator const_begin = test.begin();
		std::cout << "begin : " << const_begin->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____end_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::iterator end = test.end();
		std::cout << "end : " << (--end)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____end_const_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::const_iterator const_end = test.end();
		std::cout << "end : " << (--const_end)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____rbegin_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::reverse_iterator rbegin = test.rbegin();
		std::cout << "rbegin : " << (rbegin)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____const_rbegin_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::const_reverse_iterator const_rbegin = test.rbegin();
		std::cout << "const_rbegin : " << (const_rbegin)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____rend_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::reverse_iterator rend = test.rend();
		std::cout << "rend : " << (--rend)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____const_rend_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::const_reverse_iterator const_rend = test.rend();
		std::cout << "const_rend : " << (--const_rend)->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____empty_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		std::cout << std::boolalpha;
		std::cout << "empty : " << test.empty() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____size_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "size : " << test.size() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____max_size_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "max_size : " << test.max_size() << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____clear_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test.clear();
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____insert single pair_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____insert with hint single pair_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(test.begin(), ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____insert by iterator range_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		map test1(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test1.insert(test.begin(), test.end());
		output_my_map(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____erase by position_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test.erase(test.begin());
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____erase by key value_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test.erase("Ola");
		output_my_map(test);
		std::cout << std::endl;
	}

	{
		std::cout << "_____swap_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		map test1(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		test1.insert(ft::make_pair("Obrigad", 10));
		test1.insert(ft::make_pair("Gracias", 10));
		test1.insert(ft::make_pair("Thanks", 10));
		test1.insert(ft::make_pair("Merci", 10));
		test.swap(test1);
		output_my_map(test);
		output_my_map(test1);
		std::cout << std::endl;
	}

	{
		std::cout << "_____count_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "count number of \"Hello\"s : " << test.count("Hello") << std::endl;
		std::cout << "count number of \"Sayonara\"s : " << test.count("Sayonara") << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____find_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "find \"Hello\" : " << test.find("Hello")->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____equal_range_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "equal_range de \"Coucou\" : " << test.equal_range("Coucou").first->first << " ---- " << test.equal_range("Coucou").second->first<< std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____lower_bound_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "lower_bound de \"Coucou\" : " << test.lower_bound("Coucou")->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____upper_bound_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << "upper_bound de \"Coucou\" : " << test.upper_bound("Coucou")->first << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____key_comp_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << std::boolalpha;
		map test1(test.key_comp(), a);
		test1.insert(ft::make_pair("Hello", 10));
		test1.insert(ft::make_pair("Hi", 10));
		test1.insert(ft::make_pair("Bonjour", 10));
		test1.insert(ft::make_pair("Ola", 10));		std::cout << std::endl;
	}

	{
		std::cout << "_____relational operators_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		std::cout << std::boolalpha;
		map test1(comp, a);
		test1.insert(ft::make_pair("Obrigad", 10));
		test1.insert(ft::make_pair("Gracias", 10));
		test1.insert(ft::make_pair("Thanks", 10));
		std::cout << "> : " << (test > test1) << std::endl;
		std::cout << ">= : " << (test >= test1) << std::endl;
		std::cout << "< : " << (test < test1) << std::endl;
		std::cout << "<= : " << (test <= test1) << std::endl;
		std::cout << "== : " << (test == test1) << std::endl;
		std::cout << "!= : " << (test != test1) << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << "_____iterators_____" << std::endl;
		std::allocator<ft::pair<const std::string, int> > a;
		std::less<const std::string> comp;
		map test(comp, a);
		test.insert(ft::make_pair("Hello", 10));
		test.insert(ft::make_pair("Hi", 10));
		test.insert(ft::make_pair("Bonjour", 10));
		test.insert(ft::make_pair("Ola", 10));
		map::iterator it = test.begin();
		std::cout << (*++it).first << std::endl;
		std::cout << (*--it).first << std::endl;
		std::cout << it->first << std::endl;
	}

gettimeofday(&time, NULL);  //END-TIME

	totalTime = ((time.tv_sec * 1000) + (time.tv_usec/1000) - totalTime);

	std::cout << "Execution time is " << totalTime << std::endl;

	// time differences 
}

#elif VERSION == 1

#include <map>
#include <stack>
#include <vector>
#include <sys/time.h>

#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"






int main()
{
	int i;

	std::cout << "_____________________PERFORMANCE MAIN_____________________" << std::endl;

	
	
	std::cout << "________________MY VECTOR________________" << std::endl;
	
	
	struct timeval time;
	gettimeofday(&time, NULL); // Start Time
	unsigned long long totalTime = (time.tv_sec * 1000) + (time.tv_usec/1000);

	i = 0;
	ft::vector<int> a;
	while (i < 1000000)
		a.push_back(i++);

	gettimeofday(&time, NULL);  //END-TIME

	totalTime = ((time.tv_sec * 1000) + (time.tv_usec/1000) - totalTime);

	std::cout << "Execution time for my vector is " << totalTime << std::endl;

	std::cout << std::endl << std::endl << std::endl;


	std::cout << "________________STD VECTOR________________" << std::endl;
	
	struct timeval time1;
	gettimeofday(&time1, NULL); // Start Time
	unsigned long long totalTime1 = (time1.tv_sec * 1000) + (time1.tv_usec/1000);

	i = 0;
	std::vector<int> b;
	while (i < 1000000)
		b.push_back(i++);

	gettimeofday(&time1, NULL);  //END-TIME

	totalTime1 = ((time1.tv_sec * 1000) + (time1.tv_usec/1000) - totalTime1);

	std::cout << "Execution time for STD vector is " << totalTime1 << std::endl;

	std::cout << std::endl << std::endl << std::endl;

	std::cout << "________________MY MAP________________" << std::endl;

	struct timeval time2;
	gettimeofday(&time2, NULL); // Start Time
	unsigned long long totalTime2 = (time2.tv_sec * 1000) + (time2.tv_usec / 1000);

	ft::map<int, std::string> map_test;

	std::string stringa = "Hello";
	i = 0;
	while (i < 1000000)
		map_test.insert(ft::make_pair(i++, stringa));

	gettimeofday(&time2, NULL);  //END-TIME

	totalTime2 = ((time2.tv_sec * 1000) + (time2.tv_usec / 1000) - totalTime2);

	std::cout << "Execution time for my map is " << totalTime2 << std::endl;

	std::cout << std::endl << std::endl << std::endl;


	std::cout << "________________STD MAP________________" << std::endl;

	
	struct timeval time3;
	gettimeofday(&time3, NULL); // Start Time
	unsigned long long totalTime3 = (time3.tv_sec * 1000) + (time3.tv_usec / 1000);


	std::map<int, std::string> map_test1;

	std::string stringa1 = "Hello";
	i = 0;
	while (i < 1000000)
		map_test1.insert(std::make_pair(i++, stringa1));

	gettimeofday(&time3, NULL);  //END-TIME

	totalTime3 = ((time3.tv_sec * 1000) + (time3.tv_usec / 1000) - totalTime3);

	std::cout << "Execution time for STD map is " << totalTime3 << std::endl;

	std::cout << std::endl << std::endl << std::endl;

		std::cout << "________________MY STACK________________" << std::endl;

	struct timeval time4;
	gettimeofday(&time4, NULL); // Start Time
	unsigned long long totaltime4 = (time4.tv_sec * 1000) + (time4.tv_usec / 1000);

	ft::stack<ft::pair<int, std::string> > stack_test;

	i = 0;
	while (i < 1000000)
		stack_test.push(ft::make_pair(i++, "Hello"));

	gettimeofday(&time4, NULL);  //END-TIME

	totaltime4 = ((time4.tv_sec * 1000) + (time4.tv_usec / 1000) - totaltime4);

	std::cout << "Execution time for my stack is " << totaltime4 << std::endl;

	std::cout << std::endl << std::endl << std::endl;


	std::cout << "________________STD STACK________________" << std::endl;

	
	struct timeval time5;
	gettimeofday(&time5, NULL); // Start Time
	unsigned long long totaltime5 = (time5.tv_sec * 1000) + (time5.tv_usec / 1000);


	std::stack<std::pair<int, std::string> > stack_test1;

	i = 0;
	while (i < 1000000)
		stack_test1.push(std::make_pair(i++, "Hello"));

	gettimeofday(&time5, NULL);  //END-TIME

	totaltime5 = ((time5.tv_sec * 1000) + (time5.tv_usec / 1000) - totaltime5);

	std::cout << "Execution time for STD stack is " << totaltime5 << std::endl;

	std::cout << std::endl << std::endl << std::endl;
}



#elif VERSION==2



#include <sys/time.h>
#include <iostream>
#include <string>
#include <deque>
#if STL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class Mutantstack : public ft::stack<T>
{
public:
	Mutantstack() {}
	Mutantstack(const Mutantstack<T>& src) { *this = src; }
	Mutantstack<T>& operator=(const Mutantstack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~Mutantstack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	if (STL)
		std::cout << "_____________________RUNNING STL_____________________" << std::endl << std::endl<< std::endl;
	else
		std::cout << "_____________________RUNNING MINE_____________________" << std::endl << std::endl<< std::endl;

	std::cout << "_____________________SUBJECT MAIN_____________________" << std::endl;

	const int seed = atoi(argv[1]);
	srand(seed);
	
	struct timeval time;
	gettimeofday(&time, NULL); // Start Time

	long totalTime = (time.tv_sec * 1000) + (time.tv_usec / 1000);


	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS vector SHOULD BE EMPTY!!" <<std::endl;
		}

	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}
	

	int sum = 0;
	for (int i = 0; i < COUNT; i++)
	{
		int access = rand() % COUNT;
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	Mutantstack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (Mutantstack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	gettimeofday(&time, NULL);  //END-TIME

	totalTime = (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - totalTime);

	std::cout << "Execution time is " << totalTime << std::endl;

	std::cout << "ft::is_integral : " << ft::is_integral<unsigned int>::value << std::endl;
	return (0);
}



#elif VERSION==3




#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#include <map>
#include <stack>
#include <vector>

#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"




void test_vector();
void test_map();
void test_stack();


int main()
{
	if (STL)
		std::cout << "_____________________RUNNING STL_____________________" << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
	else
		std::cout << "_____________________RUNNING MINE_____________________" << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;

	std::cout << std::endl << std::endl << "_____________________CPLUPLUS.COM_MAIN (SOUFIANE'S MAIN)_____________________" << std::endl;

	test_vector();
	test_map();
	test_stack();

}

void test_stack()
{
	std::cout << "******STARTING TO TEST ft::STACK******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
  std::vector<int> myvector (2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
	  ft::vector<int> myvector (2,200);        // vector with 2 elements
  ft::stack<int> first;                    // empty stack
  ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  ft::stack<int,ft::vector<int> > fourth (myvector);
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------MINE_SIZE-----------" << std::endl;
{
	  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	 std::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}

std::cout << "----------STL_TOP-----------" << std::endl;
{
	 std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

}
std::cout << "----------MINE_TOP-----------" << std::endl;
{ ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}
std::cout << "----------STL_PUSH_POP-----------" << std::endl;
{
	  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}
std::cout << "----------MINE_PUSH_POP-----------" << std::endl;
{
	  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}

}


void test_map()
{
	std::cout << "******STARTING TO TEST ft::MAP******" << std::endl;
std::cout << "----------STL_INSERT-----------" << std::endl;
{
	std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
    std::map<char,int>::iterator it = mymap.begin();
	 mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  ft::map<char, int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
//  ft::map<char, int>::iterator it_test = anothermap.begin();
//  std::cout << it_test->first << std::endl;
//  it_test++;
//  std::cout << it_test->first << std::endl;
//  it_test++;

  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
//  exit(0);
}

std::cout << "----------STL_OPERATOR[]-----------" << std::endl;
{
	std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}
std::cout << "----------MINE_OPERATOR[]-----------" << std::endl;
{
  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}

std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{  
	ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
  }
std::cout << "----------STL_EMPTY-----------" << std::endl;
  {
	   std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------MINE_EMPTY-----------" << std::endl;
  {
	   ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------STL_SWAP-----------" << std::endl;
 {
	   std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_SWAP-----------" << std::endl;
 {
	   ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }

std::cout << "----------STL_ERASE-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_ERASE-----------" << std::endl;
{  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------STL_KEY__COMP-----------" << std::endl;
{std::map<char,int> mymap;

  std::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element
	std::cout << "Highest : " << highest << std::endl;

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }
std::cout << "----------MINE_KEY__COMP-----------" << std::endl;
{
	ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element
	std::cout << "Highest : " << highest << std::endl;
  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }
 
std::cout << "----------STL_VALUE__COMP-----------" << std::endl;
 {
	  std::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------MINE_VALUE__COMP-----------" << std::endl;
 {
	  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------STL_COUNT-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------MINE_COUNT-----------" << std::endl;
 {
	   ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------STL_LOWER__BOUND-----------" << std::endl;
{
	  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
std::cout << "----------MINE_LOWER__BOUND-----------" << std::endl;
{
	  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;


  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
//   ft::map<char,int>::iterator s = itlow;
//   ft::map<char,int>::iterator e = itup;
//  for (; s != itup; s++)
//	std::cout << s->first << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

std::cout << "----------STL_EQUAL__RANGE-----------" << std::endl;
{
	 std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
std::cout << "----------MINE_EQUAL__RANGE-----------" << std::endl;
{
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
}

void test_vector()
{
	std::cout << "******STARTING TO TEST ft::VECTOR******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
	  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
 std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
    std::cout << "The contents of second are:";
  for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
  for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
		  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of second are:";
  for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
    for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_OPERATOR==-----------" << std::endl;
{
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
std::cout << "----------MINE_OPERATOR==-----------" << std::endl;
{
	  ft::vector<int> foo (3,0);
  ft::vector<int> bar (5,0);

  bar = foo;
  foo = ft::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

std::cout << "----------STL_REND_RBEGIN-----------" << std::endl;
{
	  std::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_REND_RBEGIN-----------" << std::endl;
{
	  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}


std::cout << "----------STL_PUSH__BACK-----------" << std::endl;
{
  std::vector<int> myvector;


  for (int i = 19; i <= 42; i++)
    myvector.push_back(i);
 
  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}
std::cout << "----------MINE_PUSH__BACK-----------" << std::endl;
{
  ft::vector<int> myvector;
 


  for (int i = 19; i <= 42; i++)
    myvector.push_back (i);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (ft::vector<int>::iterator it=myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::cout << "----------STL_INSERT-----------" << std::endl;
{
	  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  std::vector<int> vec;
  vec.push_back(19);
  vec.push_back(21);
  vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,2,300);
  std::cout << "Blocked here" << std::endl;

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

ft::vector<int> vec;
vec.push_back(19);
vec.push_back(21);
vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------STL_IT_OP[]_OP+-----------" << std::endl;
{
	    std::vector<int>v1; 
		v1.push_back(1); 
		v1.push_back(2); 
		v1.push_back(3); 
		v1.push_back(4); 
		v1.push_back(5); 
    int i; 
  std::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i) 
        std::cout << itx[i] << " "; 
	std::cout << std::endl;
	std::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------MINE_IT_OP[]_OP+_OP-_OP+=_OP-=()-----------" << std::endl;
{
	    ft::vector<int>v1;
		v1.push_back(1); 
		v1.push_back(2); 
		v1.push_back(3); 
		v1.push_back(4); 
		v1.push_back(5); 
    int i; 
  
	ft::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i) 
        std::cout << itx[i] << " "; 
	std::cout << std::endl;
	ft::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------STL_RESIZE-----------" << std::endl;
{
	 std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_RESIZE-----------" << std::endl;
{ 
	ft::vector<int> myvector;
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}		
std::cout << "----------STL_OP[]-----------" << std::endl;
{
	  std::vector<int> myvector (10);   // 10 zero-initialized elements

  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_OP[]-----------" << std::endl;
{
	  ft::vector<int> myvector (10);   // 10 zero-initialized elements

  
  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	  std::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	  ft::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------STL_FRONT-----------" << std::endl;
{
	  std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------MINE_FRONT-----------" << std::endl;
{
	  ft::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------STL_RESERVE-----------" << std::endl;
{
  std::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------MINE_RESERVE-----------" << std::endl;
{
  ft::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------STL_AT-----------" << std::endl;
{
std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

}
std::cout << "----------MINE_AT-----------" << std::endl;
{
ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
  
}
std::cout << "----------STL_ASSIGN-----------" << std::endl;
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';	
}
std::cout << "----------MINE_ASSIGN-----------" << std::endl;
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
std::cout << "----------STL_SWAP-----------" << std::endl;
{
	 std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------MINE_SWAP-----------" << std::endl;
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------STL_NMO_REL_OP-----------" << std::endl;
{
std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------MINE_NMO_REL_OP-----------" << std::endl;
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------STL_NMO_SWAP-----------" << std::endl;
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_NMO_SWAP-----------" << std::endl;
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
}


// NEEDED FOR LIST TESTS.
// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

#elif VERSION==4

#include <iostream>
#include <vector>
#include <deque>
#include <list>

#if STL //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"

#endif

template<class T>
void	print_vec(const ft::vector<T> &v)
{
	for(typename ft::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << std::endl;
}

template<class Key, class T>
void	print_map(const ft::map<Key, T> &m)
{
	for(typename ft::map<Key, T>::const_iterator it = m.begin(); it != m.end(); ++it)
		std::cout << "Key : |" << it->first << "| Value : |" << it->second << "|" << std::endl;
}

int main()
{
	std::cout << "VECTOR" << std::endl << std::endl;
	{
		ft::vector<int>	v;

		v.push_back(10);
		v.push_back(5);
		v.push_back(0);

		ft::vector<int>::iterator		it = v.begin();
		ft::vector<int>::const_iterator	cit = v.end();

		std::cout << "-----> Iterator and const_iterator comparison" << std::endl;

		std::cout << "it == cit : " << (it == cit) << std::endl;
		std::cout << "it != cit : " << (it != cit) << std::endl;
		std::cout << "it < cit : " << (it < cit) << std::endl;
		std::cout << "it > cit : " << (it > cit) << std::endl;
		std::cout << "it <= cit : " << (it <= cit) << std::endl;
		std::cout << "it >= cit : " << (it >= cit) << std::endl;
		
		std::cout << "cit == it : " << (cit == it) << std::endl;
		std::cout << "cit != it : " << (cit != it) << std::endl;
		std::cout << "cit < it : " << (cit < it) << std::endl;
		std::cout << "cit > it : " << (cit > it) << std::endl;
		std::cout << "cit <= it : " << (cit <= it) << std::endl;
		std::cout << "cit >= it : " << (cit >= it) << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "----> Dynamic reallocation system" << std::endl;

		std::cout << "v.size() : " << v.size() << std::endl;
		std::cout << "v.capacity() : " << v.capacity() << std::endl;

		v.push_back(-5);
		v.push_back(-10);

		std::cout << std::endl << "--pushed back 2 numbers--" << std::endl;

		std::cout << "v.size() : " << v.size() << std::endl;
		std::cout << "v.capacity() : " << v.capacity() << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "-----> Swap" << std::endl;

		ft::vector<int> w(4, 100);

		std::cout << "v content:" << std::endl;
		print_vec(v);

		std::cout << "w content:" << std::endl;
		print_vec(w);

		ft::vector<int>::iterator	a = v.begin();
		std::cout << "iterator a = v.begin() : " << *a << std::endl;

		ft::swap(v, w);
		std::cout << "swap done" << std::endl;

		std::cout << "v content:" << std::endl;
		print_vec(v);

		std::cout << "w content:" << std::endl;
		print_vec(w);

		std::cout << "a is now on w.begin() : " << *a << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << "MAP" << std::endl;

	{
		std::cout << "-----> Make_pair" << std::endl;

		ft::pair<int, std::string> p = ft::make_pair(42, "lolilol");
		std::cout << p.first << p.second << std::endl;

		std::cout << "-----> Map behaviour" << std::endl;

		ft::map<int, int>	m;
		m[2] = 20;
		m[4] = 8;
		m[3] = 30;
		m[1] = 10;

		std::cout << "m content:" << std::endl;
		print_map(m);

		m[1] = 50;

		std::cout << "-----> No duplicate keys:" << std::endl;
		print_map(m);

		std::cout << "-----> Map iterator" << std::endl;

		ft::map<int, int>::iterator	it = m.find(3);

		std::cout << "it : key : |" << it->first << "| value : | " << it->second << "|" << std::endl;

		m.erase(2);
		m.erase(4);
		m.insert(ft::make_pair(2, 100));
		m.insert(ft::make_pair(4, 2));

		std::cout << "--some erases and inserts--" << std::endl;

		std::cout << "it : key : |" << it->first << "| value : | " << it->second << "|" << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << "STACK" << std::endl;

	{
		std::cout << "-----> Underlying containers" << std::endl;

		ft::stack<int, std::vector<int> > s1;
		std::cout << "ft::stack<int, std::vector<int> > s1; COMPILES" << std::endl;
		ft::stack<int, std::deque<int> > s2;
		std::cout << "ft::stack<int, std::deque<int> > s2; COMPILES" << std::endl;
		ft::stack<int, std::list<int> > s3;
		std::cout << "ft::stack<int, std::list<int> > s3; COMPILES" << std::endl;

		std::cout << "-----> Not iterable" << std::endl;

		//ft::stack<int>::iterator it;
		std::cout << "ft::stack<int>::iterator it; DOES NOT COMPILE" << std::endl; 
	}
}

#endif 
