#include "int_buffer.hpp"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int_buffer::int_buffer(size_t size) :begin_ptr(DBG_NEW int[size]), end_ptr(begin_ptr + size)
{
#if _DEBUG
	std::cout << "\tConstructor 1\n";
#endif

}

int_buffer::int_buffer(const int * source, size_t size) : int_buffer(size)
{
#if _DEBUG
	std::cout << "\tConstructor 2\n";
#endif

	for (auto i = 0; i < this->size(); i++)
	{
		begin_ptr[i] = source[i];
	}
}

int_buffer::int_buffer(const int_buffer & rhs) : int_buffer(rhs.begin(), rhs.size())
{
#if _DEBUG
	std::cout << "\tCopy constructor 3\n";
#endif
}

int_buffer::int_buffer(int_buffer && rhs)
{
#if _DEBUG
	std::cout << "\tMove constructor 4\n";
#endif

	swap(rhs);
}

int_buffer & int_buffer::operator=(const int_buffer & rhs)
{
#if _DEBUG
	std::cout << "\tCopy assign\n";
#endif

	if (this == &rhs) { return *this; }

	int_buffer tmp(rhs);
	this->swap(tmp);

	return *this;
}

int_buffer & int_buffer::operator=(int_buffer && rhs)
{
#if _DEBUG
	std::cout << "\tMove assign\n";
#endif

	if (this == &rhs) { return *this; }
	delete[] begin_ptr;
	swap(rhs);
	rhs.begin_ptr = rhs.end_ptr = nullptr;
	return *this;
}

int & int_buffer::operator[](size_t size)
{
#if _DEBUG
	std::cout << "\toperator []\n";
#endif

	return *(begin_ptr + size);
}

const int & int_buffer::operator[](size_t size) const
{
#if _DEBUG
	std::cout << "\tconst operator []\n";
#endif

	return *(begin_ptr + size);
}

size_t int_buffer::size() const
{
#if _DEBUG
	std::cout << "\tsize\n";
#endif

	return end_ptr - begin_ptr;
}

int * int_buffer::begin()
{
#if _DEBUG
	std::cout << "\tBegin\n";
#endif

	return begin_ptr;
}

int * int_buffer::end()
{
#if _DEBUG
	std::cout << "\tEnd\n";
#endif

	return end_ptr;
}

const int * int_buffer::begin() const
{
#if _DEBUG
	std::cout << "\tConst Begin\n";
#endif

	return begin_ptr;
}

const int * int_buffer::end() const
{
#if _DEBUG
	std::cout << "\tConst End\n";
#endif

	return end_ptr;
}

int_buffer::~int_buffer()
{
#if _DEBUG
	std::cout << "\tDestructor\n";
#endif

	delete[] begin_ptr;
}

void int_buffer::swap(int_buffer & rhs)
{
	std::swap(this->begin_ptr, rhs.begin_ptr);
	std::swap(this->end_ptr, rhs.end_ptr);
}
