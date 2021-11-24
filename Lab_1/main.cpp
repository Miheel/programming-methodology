#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

#if _DEBUG
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "int_buffer.hpp"
#include "int_sorted.hpp"

void f(int_buffer buf);
void print_buffer(int_buffer buf);
void print_sorted(int_sorted buf);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#if _DEBUG
	std::cout << "Debug\n";
#else
	std::cout << "Release\n";
#endif
	srand(time(NULL));

	std::cout << "ibuf\n";
	int_buffer ibuf(5);
	std::cout << "sbuf\n";
	int_sorted sbuf(nullptr, 0);

	std::cout << "\nLoad and Print ibuf f()\n";
	f(ibuf);

	std::cout << "\nLoad ibuf\n";
	int counter = 10;
	for (int* i = ibuf.begin(); i != ibuf.end(); i++)
	{
		*i = counter++;
	}
	std::cout << "\nPrint ibuf print_buffer()\n";
	print_buffer(ibuf);

	std::cout << "\nLoad sbuf\n";
	for (auto i = 0; i < 100; i++)
	{
		sbuf.insert(rand() % 100);
	}
	sbuf.insert(-1);
	sbuf.insert(200);

	std::cout << "\nPrint sbuf print_sorted()\n";
	print_sorted(sbuf);
	std::cout << "\nsbuf size: " << sbuf.size() << \
				"\nsbuf begin: " << *sbuf.begin() <<\
				"\nsbuf end: " << *(sbuf.end()-1) << "\n";

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
