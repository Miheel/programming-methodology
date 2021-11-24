#include <utility>
#include "int_sorted.hpp"

#if _DEBUG
#include <iostream>
#endif


int_sorted::int_sorted(const int * source, size_t size) :buf(source, size)
{
#if _DEBUG
	std::cout << "int_sorted_constructor\n";
#endif
}

size_t int_sorted::size() const
{
	return buf.size();
}

void int_sorted::insert(int value)
{
#if _DEBUG
	std::cout << "create int_sorted in insert\n";
#endif

	int_sorted tmp(&value, 1);

#if _DEBUG
	std::cout << "move to this in insert\n";
#endif

	*this = std::move(this->merge(tmp));
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
	std::cout << "create int_buffer in merge\n";
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

#if _DEBUG
	std::cout << "create int_sorted in merge\n";
#endif

	int_sorted new_sorted(nullptr, merge_to.size());

#if _DEBUG
	std::cout << "move in merge\n";
#endif

	new_sorted.buf = std::move(merge_to);
#if _DEBUG
	std::cout << "return from merge\n";
#endif
	return new_sorted;
}

int_sorted::~int_sorted()
{
#if _DEBUG
	std::cout << "int_sorted_destructor size:" << this->size() << "\n";
#endif

}
