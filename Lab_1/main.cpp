#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>
#include <time.h> //time
#include <stdlib.h> //rand, srand
#include <cstddef> //size_t, prtdiff_t
#include "int_sorted.hpp"

using time_point = std::chrono::time_point<std::chrono::steady_clock>;
using clock = std::chrono::high_resolution_clock;
using time_duration = std::chrono::duration<double>;

#if _DEBUG
#include <crtdbg.h>
#endif

void f(int_buffer buf);
void print_buffer(int_buffer buf);
void print_sorted(int_sorted buf);
void buf_insight(std::string name, size_t size, const int* begin, const int * end);
int_sorted sort(const int* begin, const int* end);
void selectionSort(int* begin, int* end);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#if _DEBUG
	std::cout << "Debug\n";
#else
	std::cout << "Release\n";
#endif
	srand(time(NULL));

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
	//	*i = counter++;
	//}
	//std::cout << "\nPrint ibuf print_buffer()\n";
	//print_buffer(ibuf);
	//std::cout << "\nLoad sbuf\n";
	//for (auto i = 0; i < 100; i++)
	//{
	//	sbuf.insert(rand() % 100);
	//}
	//sbuf.insert(-1);
	//sbuf.insert(200);


	int buf_size = 400000;
	int iterations = 100;
	int_buffer rand_buf(buf_size);

	time_point start, stop;
	time_duration elapsed_time;

#pragma region std::sort lots
	//std::cout << "\tBegin sorting with ins_sort\n";
	//for (size_t i = 0; i < iterations; i++)
	//{
	//	for (auto i = rand_buf.begin(); i != rand_buf.end(); i++)
	//	{
	//		*i = rand() % 10000;
	//	}

	//	start = clock::now();
	//	std::sort(rand_buf.begin(), rand_buf.end());
	//	stop = clock::now();

	//	elapsed_time += (stop - start);
	//}

	//std::cout << "\tEnd sorting\n";
	//std::cout << "\nTime to sort " << buf_size << " elements " << iterations << " times\n" \
	//	<< "total: " << elapsed_time.count() << "s\n" \
	//	<< "average: " << elapsed_time.count() / iterations << "s\n";
#pragma endregion

	for (auto i = rand_buf.begin(); i != rand_buf.end(); i++)
	{
		*i = rand() % 10000;
	}
	auto new_rand_buf = rand_buf;

	std::cout << "Merge sort begin\n";
	start = clock::now();
	int_sorted sorted(sort(rand_buf.begin(), rand_buf.end()));
	stop = clock::now();

	elapsed_time = stop - start;
	std::cout << "\n\tTime to sort " << buf_size << " element\n" \
		<< "\telapsed time: " << elapsed_time.count() << "s\n";

	//std::cout << "print sorted\n";
	//print_sorted(sorted);
	std::cout << "Merge sort end\n\n";



	std::cout << "std::sort begin\n";
	start = clock::now();
	std::sort(rand_buf.begin(), rand_buf.end());
	stop = clock::now();

	elapsed_time = stop - start;
	std::cout << "\n\tTime to sort " << buf_size << " element\n" \
		<< "\telapsed time: " << elapsed_time.count() << "s\n";

	//std::cout << "print rand_buf\n";
	//print_buffer(rand_buf);
	std::cout << "std::sort end\n\n";



	std::cout << "Selectionsort begin\n";
	//start = clock::now();
	//selectionSort(new_rand_buf.begin(), new_rand_buf.end());
	//stop = clock::now();

	//elapsed_time = stop - start;
	//std::cout << "\n\tTime to sort " << buf_size << " element\n" \
	//	<< "\telapsed time: " << elapsed_time.count() << "s\n";

	//std::cout << "print new_rand_buf\n";
	//print_buffer(new_rand_buf);
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
	std::cout << "\n" << name << " size: " << size << \
		"\n" << name << " begin: " << *begin << \
		"\n" << name << " end: " << *(end - 1) << "\n";
}

int_sorted sort(const int * begin, const int * end)
{
	if (begin == end)
		return int_sorted(nullptr, 0);

	if (begin == end - 1)
		return int_sorted(begin, 1);

	std::ptrdiff_t half = (end - begin) / 2;
	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));
}

void selectionSort(int * begin, int * end)
{
	for (auto it = begin; it != end; it++)
	{
		auto min = it;

		for (auto j = it + 1; j != end; j++)
		{
			if (*j < *min)
				min = j;
		}
		std::swap(*it, *min);
	}
}
