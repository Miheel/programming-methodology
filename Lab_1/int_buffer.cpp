#include <utility>
#include <algorithm>
#include "int_buffer.hpp"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int_buffer::int_buffer(size_t size) :begin_ptr(DBG_NEW int[size]), end_ptr(begin_ptr + size)
{
#if _DEBUG
	std::cout << "\tint_buffer Constructor 1\n";
#endif
}

int_buffer::int_buffer(const int * source, size_t size) : int_buffer(size)
{
#if _DEBUG
	std::cout << "\tint_buffer Constructor 2\n";
#endif
	//if (source != nullptr)
	//{
	//	for (size_t i = 0; i < this->size(); i++)
	//	{
	//		begin_ptr[i] = source[i];
	//	}
	//}
	std::copy(source, source + size, begin_ptr);
}

int_buffer::int_buffer(const int_buffer & rhs) : int_buffer(rhs.begin(), rhs.size())
{
#if _DEBUG
	std::cout << "\tint_buffer Copy constructor 3\n";
#endif
}

int_buffer::int_buffer(int_buffer && rhs)
{
#if _DEBUG
	std::cout << "\tint_buffer Move constructor 4\n";
#endif

	swap(rhs);
}

int_buffer & int_buffer::operator=(const int_buffer & rhs)
{
#if _DEBUG
	std::cout << "\tint_buffer Copy assign\n";
#endif

	int_buffer tmp(rhs);
	this->swap(tmp);

	return *this;
}

int_buffer & int_buffer::operator=(int_buffer && rhs)
{
#if _DEBUG
	std::cout << "\tint_buffer Move assign\n";
#endif

	swap(rhs);

	return *this;
}

int & int_buffer::operator[](size_t size)
{
#if _DEBUG
	std::cout << "\tint_buffer operator []\n";
#endif

	return *(begin_ptr + size);
}

const int & int_buffer::operator[](size_t size) const
{
#if _DEBUG
	std::cout << "\tint_buffer const operator []\n";
#endif

	return *(begin_ptr + size);
}

size_t int_buffer::size() const
{
#if _DEBUG
	std::cout << "\tint_buffer size\n";
#endif

	return end_ptr - begin_ptr;
}

int * int_buffer::begin()
{
#if _DEBUG
	std::cout << "\tint_buffer Begin\n";
#endif

	return begin_ptr;
}

int * int_buffer::end()
{
#if _DEBUG
	std::cout << "\tint_buffer End\n";
#endif

	return end_ptr;
}

const int * int_buffer::begin() const
{
#if _DEBUG
	std::cout << "\tint_buffer Const Begin\n";
#endif

	return begin_ptr;
}

const int * int_buffer::end() const
{
#if _DEBUG
	std::cout << "\tint_buffer Const End\n";
#endif

	return end_ptr;
}

int_buffer::~int_buffer()
{
#if _DEBUG
	std::cout << "\tint_buffer Destructor\n";
#endif

	delete[] begin_ptr;
}

void int_buffer::swap(int_buffer & rhs)
{
	std::swap(this->begin_ptr, rhs.begin_ptr);
	std::swap(this->end_ptr, rhs.end_ptr);
}
