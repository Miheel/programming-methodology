#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "p_queue.hpp"

struct Orders
{
	std::string name;
	int price;
	bool operator>=(const Orders& rhs) const
	{
		return this->price >= rhs.price;
	}
	std::string toString() {
		return "Name: " + name + " price:" + std::to_string(price);
	}
};

struct CompGreater
{
	bool operator()(const Orders& lhs,const Orders& rhs) const
	{
		return lhs.price > rhs.price;
	}
};

int main()
{
	srand(time(NULL));
	p_queue<Orders, CompGreater> buyer, seller;

	for (size_t i = 0; i < 7; i++)
	{
		buyer.push({ "Erik Pendel", rand() % 15 + 15 });
		buyer.push({ "Jarl Wallenburg", rand() % 15 + 15 });
		buyer.push({ "Joakim von Anka", rand() % 15 + 15 });
		seller.push({ "Erik Pendel", rand() % 15 + 15 });
		seller.push({ "Jarl Wallenburg", rand() % 15 + 15 });
		seller.push({ "Joakim von Anka", rand() % 15 + 15 });
	}

	while (!buyer.empty() )
	{

		auto buy_tmp = buyer.pop();
		auto sell_tmp = seller.pop();

		if (buy_tmp >=sell_tmp)
		{
			std::cout << "Buyer " << buy_tmp.toString() << "\tSeller " << sell_tmp.toString() << "\n"; 
		}
	}

	getchar();
	return 0;
}