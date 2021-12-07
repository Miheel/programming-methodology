#include <iostream>
#include <array>
#include <memory>
#include "parallelepiped.hpp"
#include "roundedRectangle.hpp"
#include "cylinder.hpp"

template<typename T, size_t size>
void getData(std::array<T, size> &list) {

	for (auto i = list.begin(); i < list.end() && *i != nullptr; i++)
	{
		std::cout << "Area: " << (*i)->getArea() << " Colour: " << (*i)->getColour() << " Type: " << typeid(**i).name() << "\n";
	}
	std::cout << "\n";
}

int main()
{
	std::array<std::shared_ptr<Shape>, 10> shapeArr;

	shapeArr.at(0) = std::make_shared<Rectangle>(1, 5, "red");
	shapeArr.at(1) = std::make_shared<Parallelepiped>(2, 6, 3, "blue");
	shapeArr.at(2) = std::make_shared<RoundedRectangle>(10, 4, 3, "green");
	shapeArr.at(3) = std::make_shared<Circle>(4, "pink");
	shapeArr.at(4) = std::make_shared<Cylinder>(4, 6, "black");

	getData(shapeArr);

	shapeArr.at(5) = std::make_shared<Circle>(10, "magenta");
	shapeArr.at(6) = std::make_shared<Cylinder>(6, 11, "cyan");

	getData(shapeArr);


	getchar();
	return 0;
}
