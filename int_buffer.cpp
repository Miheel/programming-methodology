#include "int_buffer.hpp"

int_buffer::int_buffer(size_t size):begin_ptr(new int[size]), end_ptr(begin_ptr + size)
{
}

int_buffer::int_buffer(const int * source, size_t size): int_buffer(size)
{
	for (auto i = 0; i < this->size(); i++)
	{
		begin_ptr[i] = source[i];
	}
}

int_buffer::int_buffer(const int_buffer & rhs): int_buffer(rhs.begin(), rhs.size())
{
}

int_buffer::int_buffer(int_buffer && rhs)
{
}

//int_buffer & int_buffer::operator=(const int_buffer & rhs)
//{
//	// TODO: insert return statement here
//}
//
//int_buffer & int_buffer::operator=(int_buffer && rhs)
//{
//	// TODO: insert return statement here
//}

int & int_buffer::operator[](size_t size)
{
	return *(begin_ptr + size);
}

const int & int_buffer::operator[](size_t size) const
{
	return *(begin_ptr + size);
}

size_t int_buffer::size() const
{
	return end_ptr - begin_ptr;
}

int * int_buffer::begin()
{
	return begin_ptr;
}

int * int_buffer::end()
{
	return end_ptr;
}

const int * int_buffer::begin() const
{
	return begin_ptr;
}

const int * int_buffer::end() const
{
	return end_ptr;
}

int_buffer::~int_buffer()
{
}
