#ifndef MYPRINT_HPP
#define MYPRINT_HPP

#include "car.hpp"

class MyPrint
{
public:
	void operator()(const Car& carList);
};
#endif // !MYPRINT_HPP
