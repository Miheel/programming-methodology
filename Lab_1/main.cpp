#include "int_buffer.hpp"
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
void f(int_buffer buf);
void print_range(int_buffer buf);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#if _DEBUG
	std::cout << "Debug\n";
#else
	std::cout << "Release\n";
#endif

	std::cout << "ibuf\n";
	int_buffer ibuf(5);
	std::cout << "Load ibuf\n";
	int counter = 0;
	for (int* i = ibuf.begin(); i != ibuf.end(); i++)
	{
		*i = counter++;
	}
	std::cout << "\nprint ibuf in print_range\n";
	print_range(ibuf);

	std::cout << "\nprint ibuf in f\n";
	f(ibuf);

	std::cout << "\ncopy ibuf to i2\n";
	int_buffer i2(ibuf);

	std::cout << "\nresize ibuf to i3\n";
	int_buffer i3(ibuf.begin(), 10);

	std::cout << "\nprint i2\n";
	print_range(i2);

	std::cout << "\nprint i3\n";
	print_range(i3);

	std::cout << "\ncopy assign\n";
	int_buffer copyTo(10);
	std::cout << "\nBefore copy\ncopyTo\n";
	print_range(copyTo);
	copyTo = ibuf;
	std::cout << "\nAfter copy\ncopyTo\n";
	print_range(copyTo);
	std::cout << "\nibuf\n";
	print_range(ibuf);

	std::cout << "\nMove constructor\n";
	int_buffer movedTo = std::move(ibuf);
	std::cout << "\nprint moved to\n";
	print_range(movedTo);
	std::cout << "\nprint ibuf\n";
	print_range(ibuf);

	std::cout << "\nMove assign\n";
	int_buffer movedTo2(10);
	movedTo2 = std::move(movedTo);
	std::cout << "\nprint moved to 2\n";
	print_range(movedTo2);
	std::cout << "\nprint moved to\n";
	print_range(movedTo);

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

void print_range(int_buffer buf)
{
	for (auto e : buf)
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
}
