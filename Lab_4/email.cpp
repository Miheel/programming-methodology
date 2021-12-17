#include "email.hpp"

Email::Email(std::string name, std::string date, std::string subject)
	:name(name), date(date), subject(subject)
{
}

bool CompWhoDateSubject::operator()(const Email & lhs, const Email & rhs)
{
	if (lhs.name < rhs.name) return true;
	else if (lhs.name == rhs.name)
	{
		if (lhs.date < rhs.date) return true;
		else if (lhs.date == rhs.date)
		{
			if (lhs.subject < rhs.subject) return true;
		}
	}
	return false;
}

bool CompDateWhoSubject::operator()(const Email & lhs, const Email & rhs)
{
	if (lhs.date < rhs.date) return true;
	else if (lhs.date == rhs.date)
	{
		if (lhs.name < rhs.name) return true;
		else if (lhs.name == rhs.name)
		{
			if (lhs.subject < rhs.subject) return true;
		}
	}
	return false;
}

bool CompSubjectWhoDate::operator()(const Email & lhs, const Email & rhs)
{
	if (lhs.subject < rhs.subject) return true;
	else if (lhs.subject == rhs.subject)
	{
		if (lhs.name < rhs.name) return true;
		else if (lhs.name == rhs.name)
		{
			if (lhs.date < rhs.date) return true;
		}
	}
	return false;
}

std::ostream & operator<<(std::ostream & out, Email & email)
{
	return out << "\tFrom: " << email.name << " Date: " << email.date << " Subject: " << email.subject;
}
