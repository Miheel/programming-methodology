#include "car.hpp"

Car::Car(std::string name, double age):name(name), age(age)
{
}

bool operator==(const Car & lhs, const Car & rhs)
{
	return lhs.name == rhs.name;
}
