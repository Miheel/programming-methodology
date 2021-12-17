#include <iostream>
#include "myPrint.hpp"

void MyPrint::operator()(const Car & carList)
{
	std::cout << "Name: " << carList.name << " Age: " << carList.age << "\n";
}