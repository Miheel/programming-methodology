#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "p_queue.hpp"

struct Orders
{
	std::string name;
	int price;

	friend std::ostream& operator<<(std::ostream & out, const Orders& obj)
	{
		return out << "Name: " + obj.name + " price:" + std::to_string(obj.price);
	}
};

template<>
struct std::less<Orders>
{
	bool operator()(const Orders& lhs, const Orders&rhs) const
	{
		return lhs.price < rhs.price;
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	p_queue<Orders> buyer, seller;

	for (size_t i = 0; i < 7; i++)
	{
		buyer.push({ "Erik Pendel", rand() % 15 + 15 });
		buyer.push({ "Jarl Wallenburg", rand() % 15 + 15 });
		buyer.push({ "Joakim von Anka", rand() % 15 + 15 });
		seller.push({ "Erik Pendel", rand() % 15 + 15 });
		seller.push({ "Jarl Wallenburg", rand() % 15 + 15 });
		seller.push({ "Joakim von Anka", rand() % 15 + 15 });
	}
	
	while (!buyer.empty() && !seller.empty())
	{
		auto buy_tmp = buyer.pop();
		auto sell_tmp = seller.pop();
		if (buy_tmp.price >= sell_tmp.price)
		{
			std::cout << "Buyer max prize " << buy_tmp << "\tSeller minimum prize " << sell_tmp << "\n";
		}
		else
		{
			seller.push(sell_tmp);
		}
	}

	return 0;
}
