#ifndef CAR_HPP
#define CAR_HPP

#include <string>
class Car
{
public:
	Car() = default;
	Car(std::string name, double age);
	friend bool operator==(const Car& lhs, const Car& rhs);

	std::string name;
	double age;
};

#endif // !CAR_HPP
