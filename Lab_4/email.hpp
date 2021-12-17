#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>
#include <ostream>

class Email
{
public:
	Email(std::string name, std::string date, std::string subject);

	friend std::ostream& operator<< (std::ostream& out, Email &email);

	friend struct CompWhoDateSubject;
	friend struct CompDateWhoSubject;
	friend struct CompSubjectWhoDate;

private:
	std::string name;
	std::string date;
	std::string subject;
};

struct CompWhoDateSubject
{
	bool operator()(const Email& lhs, const Email& rhs);
};

struct CompDateWhoSubject
{
	bool operator()(const Email& lhs, const Email& rhs);
};

struct CompSubjectWhoDate
{
	bool operator()(const Email& lhs, const Email& rhs);
};

#endif // !EMAIL_HPP
