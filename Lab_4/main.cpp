#include <iostream>
#include "mailBox.hpp"

#include <vector>
#include <algorithm>

void print_vec(const MailBox& vec) {
	for (auto e : vec)
	{
		std::cout << e << "\n";
	}
	std::cout << "\n";
}

int main()
{
	MailBox mailBox;
	mailBox.push_back({ "Niklas", "2021-12-14", "vilken kung man är grabbar" });
	mailBox.push_back({ "Robin", "1997-09-01", "hmm det är jobbigt" });
	mailBox.push_back({ "carl", "2018-5-10", "Motivera ditt svar" });
	mailBox.push_back({ "Anders", "2002-02-28", "lab 1" });
	mailBox.push_back({ "Anders", "2002-02-28", "lab 2" });
	mailBox.push_back({ "Anders", "2002-03-28", "lab 2" });
	mailBox.push_back({ "Anders", "2002-01-28", "lab 2" });


	std::cout << "Before sort\n";
	print_vec(mailBox);

	mailBox.SortWho();
	std::cout << "\nAfter SortWho\n";
	print_vec(mailBox);

	mailBox.SortDate();
	std::cout << "\nAfter SortDate\n";
	print_vec(mailBox);

	mailBox.SortSubject();
	std::cout << "\nAfter SortSubject\n";
	print_vec(mailBox);

	getchar();

	return 0;
}
