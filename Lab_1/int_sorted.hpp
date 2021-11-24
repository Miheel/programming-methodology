#ifndef INT_SORTED_HPP
#define INT_SORTED_HPP

#include <cstdlib>
#include "int_buffer.hpp"

class int_sorted
{
public:
	int_sorted(const int* source, size_t size);

	int_sorted(const int_sorted& rhs) = default; //copy constructor
	int_sorted(int_sorted&& rhs) = default; //move constructor

	int_sorted& operator= (const int_sorted& rhs) = default; //copy assign
	int_sorted& operator= (int_sorted&& rhs) = default; //move assign

	size_t size() const;
	void insert(int value);
	const int* begin() const;
	const int* end() const;
	int_sorted merge(const int_sorted& merge_with) const;
	~int_sorted();

private:
	int_buffer buf;
};
#endif // !INT_SORTED_HPP
