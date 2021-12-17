#include <iostream>
#include <array>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include "car.hpp"
#include "myPrint.hpp"


class GreaterThanVolvo
{
public:
	bool operator()(const Car& car)const {
		return car.name > "Nisan";
	}
};

class MyBinOp
{
public:
	double operator()(const double&init, const Car&car)const {
		return init + car.age;
	}
};

class MyUnOp
{
public:
	double operator()(const Car& car)const {
		return car.age;
	}
};

class MyFunc
{
public:
	MyFunc(double mean) :mean(mean) {}
	double operator()(const double& carage) const {
		return carage + mean;
	}
private:
	double mean;
};


int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	const int cap = 10;
	std::array<Car, cap> cars;
	std::string car_names[] = { "Volvo", "Saab", "Nisan", "Skoda", "Ferrari", "Rolls Royce" };
	auto car_name_size = sizeof(car_names) / sizeof(std::string);

	for (size_t i = 0; i < cars.size(); i++)
	{
		cars[i] = { car_names[rand() % car_name_size], (double)(rand() % 10 + 1) };
	}

	std::vector<Car> car_vec(cars.begin(), cars.end());

	/***1***/
	MyPrint print;
	std::for_each(car_vec.begin(), car_vec.end(), print);

	/***2***/
	GreaterThanVolvo GTVolvo;
	auto found = std::find_if(car_vec.begin(), car_vec.end(), GTVolvo);
	std::cout << "Found: ";
	if (found != car_vec.end())
		print(*found);

	/***3***/
	auto found_adj = std::adjacent_find(car_vec.begin(), car_vec.end());
	std::cout << "Found first adjacent: ";
	if (found_adj != car_vec.end())
		print(*found_adj);
	else
		std::cout << "No adjacent elements found\n";

	/***4***/
	bool is_equal = std::equal(car_vec.begin(), car_vec.end(), cars.begin());
	std::cout << "cars and car_vec is equal: " << std::boolalpha << is_equal << "\n";

	/***5***/
	auto it = std::search(car_vec.begin(), car_vec.end(), cars.begin() + 3, cars.end());
	std::cout << "subsection\n";
	std::for_each(it, car_vec.end(), print);

	/***6***/
	auto sum = std::accumulate(car_vec.begin(), car_vec.end(), 0.0, MyBinOp());
	auto mean = sum / car_vec.size();
	std::cout << "sum of car age: " << sum << " Mean of car age: " << mean << "\n";

	/***7***/
	std::vector<double> v2(car_vec.size());
	std::transform(car_vec.begin(), car_vec.end(), v2.begin(), MyUnOp());

	/***8***/
	//MyFunc myFunc(mean);
	std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(mean));

	/***9***/
	std::sort(v2.begin(), v2.end());
	for (auto e : v2) {
		std::cout << e << ", ";
	}

	//getchar();
	return 0;
}