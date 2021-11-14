#include "int_buffer.hpp"
#include <iostream>
#include <vector>
void f(int_buffer& buf);
void print_range(int_buffer& buf);

int main() {
	int_buffer ibuf(5);

	f(ibuf);
	int_buffer i3(ibuf);

	int_buffer i2(ibuf.begin(), 10);
	print_range(i2);
	print_range(i3);
	getchar();
	return 0;
}

void f(int_buffer &buf){
	int counter = 0;
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

void print_range(int_buffer & buf)
{
	for (auto e : buf)
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
}
