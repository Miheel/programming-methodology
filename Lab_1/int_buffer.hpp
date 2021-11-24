#ifndef INT_BUFFER_HPP
#define INT_BUFFER_HPP

#include <cstdlib>

class int_buffer
{
public:

	//constructors
	explicit int_buffer(size_t size);
	int_buffer(const int* source, size_t size);
	int_buffer(const int_buffer& rhs); //copy constructor
	int_buffer(int_buffer&& rhs); //move constructor

	//Assign
	int_buffer& operator= (const int_buffer& rhs); //copy assign
	int_buffer& operator= (int_buffer&& rhs); //move assign

	//Access
	int& operator[] (size_t size);
	const int& operator[] (size_t size) const;

	size_t size() const;

	int* begin();
	int* end();
	
	const int* begin() const;
	const int* end() const;

	~int_buffer();

private:
	void swap(int_buffer& rhs);

	int* begin_ptr = nullptr;
	int* end_ptr = nullptr;
};
#endif // !INT_BUFFER_HPP
