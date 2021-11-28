#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <time.h> //time
#include <stdlib.h> //rand, srand
#include <cstddef> //size_t, prtdiff_t
#include "int_sorted.hpp"

//visual studio release and debug mode flag
#if _DEBUG
#include <crtdbg.h>
#endif

//using time_point = std::chrono::time_point<std::chrono::steady_clock>;
//using clock = std::chrono::high_resolution_clock;
using time_duration = std::chrono::duration<double>;

void f(int_buffer buf);
void print_buffer(int_buffer buf);
void print_sorted(int_sorted buf);
void buf_insight(std::string name, size_t size, const int* begin, const int * end);
int_sorted sort(const int* begin, const int* end);
void selectionSort(int* begin, int* end);

int main()
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::cout << "Debug\n";
#else
	std::cout << "Release\n";
#endif
	srand(static_cast<unsigned int>(time(NULL)));

	//std::cout << "ibuf\n";
	//int_buffer ibuf(5);
	//std::cout << "sbuf\n";
	//int_sorted sbuf(nullptr, 0);
	//std::cout << "\nLoad and Print ibuf f()\n";
	//f(ibuf);
	//std::cout << "\nLoad ibuf\n";
	//int counter = 10;
	//for (int* i = ibuf.begin(); i != ibuf.end(); i++)
	//{
	//	*i = rand() % 10;
	//}
	//std::cout << "\nPrint ibuf print_buffer()\n";
	//print_buffer(ibuf);
	//std::cout << "\nLoad sbuf\n";
	//for (auto i = 0; i < 10; i++)
	//{
	//	sbuf.insert(rand() % 100);
	//}
	//sbuf.insert(-1);
	//sbuf.insert(200);
	//
	//int_sorted new_buf(ibuf.begin(), ibuf.size());
	//print_sorted(new_buf);

	int buf_size = 400000;
	//int iterations = 100;
	int_buffer rand_buf(buf_size);

	const int_buffer const_buf(buf_size);
	const_buf.begin();
	rand_buf.begin();

	//time_point start, stop;
	time_duration elapsed_time;

	/********************************sort with iterations********************************/
	//std::cout << "\tBegin sorting with ins_sort\n";
	//for (size_t i = 0; i < iterations; i++)
	//{
	//	for (auto i = rand_buf.begin(); i != rand_buf.end(); i++)
	//	{
	//		*i = rand() % 10000;
	//	}
	//
	//	start = clock::now();
	//	std::sort(rand_buf.begin(), rand_buf.end());
	//	stop = clock::now();
	//
	//	elapsed_time += (stop - start);
	//}
	//
	//std::cout << "\tEnd sorting\n";
	//std::cout << "\nTime to sort " << buf_size << " elements " << iterations << " times\n";
	//std::cout << "total: " << elapsed_time.count() << "s\n";
	//std::cout << "average: " << elapsed_time.count() / iterations << "s\n";
	/**************************************************************************/



	for (auto i = rand_buf.begin(); i != rand_buf.end(); i++)
	{
		*i = rand() % 10000;
	}
	auto new_rand_buf = rand_buf;

	/********************************Merge sort********************************/
	std::cout << "Merge sort begin\n";
	auto start = std::chrono::high_resolution_clock::now();
	int_sorted sorted(sort(rand_buf.begin(), rand_buf.end()));
	auto stop = std::chrono::high_resolution_clock::now();

	elapsed_time = stop - start;
	std::cout << "\n\tTime to sort " << buf_size << " element\n";
	std::cout << "\telapsed time: " << elapsed_time.count() << "s\n";

	//std::cout << "print sorted\n";
	//print_sorted(sorted);
	buf_insight("sorted", sorted.size(), sorted.begin(), sorted.end());
	std::cout << "Merge sort end\n\n";


	/********************************std::sort********************************/
	std::cout << "std::sort begin\n";
	start = std::chrono::high_resolution_clock::now();
	std::sort(rand_buf.begin(), rand_buf.end());
	stop = std::chrono::high_resolution_clock::now();

	elapsed_time = stop - start;
	std::cout << "\n\tTime to sort " << buf_size << " element\n";
	std::cout << "\telapsed time: " << elapsed_time.count() << "s\n";

	//std::cout << "print rand_buf\n";
	//print_buffer(rand_buf);
	buf_insight("rand_buf", rand_buf.size(), rand_buf.begin(), rand_buf.end());
	std::cout << "std::sort end\n\n";


	/********************************Selectionsort********************************/
	std::cout << "Selectionsort begin\n";
	std::cout << "Commented out to save time\n";
	//start = std::chrono::high_resolution_clock::now();
	//selectionSort(new_rand_buf.begin(), new_rand_buf.end());
	//stop = std::chrono::high_resolution_clock::now();
	//
	//elapsed_time = stop - start;
	//std::cout << "\n\tTime to sort " << buf_size << " element\n";
	//std::cout << "\telapsed time: " << elapsed_time.count() << "s\n";
	//
	////std::cout << "print new_rand_buf\n";
	////print_buffer(new_rand_buf);
	//buf_insight("new_rand_buf", new_rand_buf.size(), new_rand_buf.begin(), new_rand_buf.end());
	std::cout << "Selectionsort end\n\n";

}

void f(int_buffer buf)
{
	int counter = 10;
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		*i = counter++;
	}
	for (const int* i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << ", ";
	}
	std::cout << "\n";
}

void print_buffer(int_buffer buf)
{
	for (auto e : buf)
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
}

void print_sorted(int_sorted buf)
{
	for (auto e : buf)
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
}

void buf_insight(std::string name, size_t size, const int * begin, const int * end)
{
	std::cout << "\n\t" << name << " size: " << size;
	std::cout << "\n\t" << name << " begin: " << *begin;
	std::cout << "\n\t" << name << " end: " << *(end - 1) << "\n";
}

void selectionSort(int * first, int * last)
{
	for (; first != last; first++)
	{
		auto min = std::min_element(first, last);
		std::iter_swap(min, first);
	}
}
