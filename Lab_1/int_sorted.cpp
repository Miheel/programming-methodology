#include <utility>
#include "int_sorted.hpp"

#if _DEBUG
#include <iostream>
#endif

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

int_sorted::int_sorted(const int * source, size_t size) :buf(nullptr, 0)
{
#if _DEBUG
	std::cout << "int_sorted_constructor\n";
#endif
	if (size == 1)
	{
		buf = int_buffer(source, 1);
	}
	else if( size > 1)
	{
	buf = sort(source, source + size).buf;
	}

}

size_t int_sorted::size() const
{
	return buf.size();
}

void int_sorted::insert(int value)
{
#if _DEBUG
	std::cout << "Insert\n";
#endif
	int_sorted tmp(&value, 1);

	*this = this->merge(tmp);
}

const int * int_sorted::begin() const
{
	return buf.begin();
}

const int * int_sorted::end() const
{
	return buf.end();
}

int_sorted int_sorted::merge(const int_sorted & merge_with) const
{
#if _DEBUG
	std::cout << "Merge\n";
#endif

	int_buffer merge_to(buf.size() + merge_with.size());
	auto this_begin = this->begin();
	auto merge_begin = merge_with.begin();
	auto merge_to_iter = merge_to.begin();
	while ((this_begin != this->end()) && (merge_begin != merge_with.end()))
	{
		if (*this_begin < *merge_begin)
		{
			*merge_to_iter = *this_begin;
			this_begin++;
			merge_to_iter++;
		}
		else
		{
			*merge_to_iter = *merge_begin;
			merge_begin++;
			merge_to_iter++;
		}
	}
	while (this_begin != this->end())
	{
		*merge_to_iter = *this_begin;
		this_begin++;
		merge_to_iter++;

	}
	while (merge_begin != merge_with.end())
	{
		*merge_to_iter = *merge_begin;
		merge_begin++;
		merge_to_iter++;
	}

	int_sorted new_sorted(nullptr, 0);

	new_sorted.buf = merge_to;
	return new_sorted;
}

int_sorted::~int_sorted()
{
#if _DEBUG
	std::cout << "int_sorted_destructor size:" << this->size() << "\n";
#endif
}
