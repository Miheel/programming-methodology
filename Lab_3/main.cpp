#include "p_queue.hpp"

#include <stdlib.h>
#include <time.h>

struct Orders
{
	std::string name;
	int price;
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

	


	return 0;
}