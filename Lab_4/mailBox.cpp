#include <algorithm>
#include "mailBox.hpp"

Email & MailBox::operator[](size_t index)
{
	return emailList[index];
}

const Email & MailBox::operator[](size_t index) const
{
	return emailList[index];
}

void MailBox::push_back(Email email)
{
	emailList.push_back(email);
}

std::vector<Email>::iterator MailBox::begin() noexcept
{
	return emailList.begin();
}

std::vector<Email>::iterator MailBox::end() noexcept
{
	return emailList.end();
}

std::vector<Email>::const_iterator MailBox::begin() const noexcept
{
	return emailList.begin();
}

std::vector<Email>::const_iterator MailBox::end() const noexcept
{
	return emailList.end();
}

void MailBox::SortWho()
{
	CompWhoDateSubject comp;
	std::sort(emailList.begin(), emailList.end(), comp);
}

void MailBox::SortDate()
{
	CompDateWhoSubject comp;
	std::sort(emailList.begin(), emailList.end(), comp);
}

void MailBox::SortSubject()
{
	CompSubjectWhoDate comp;
	std::sort(emailList.begin(), emailList.end(), comp);
}
