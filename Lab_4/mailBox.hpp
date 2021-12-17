#ifndef MAILBOX_HPP
#define MAILBOX_HPP

#include <vector>
#include <cstddef>
#include "email.hpp"

using email_vec = std::vector<Email>;
using vec_iter = email_vec::iterator;
using vec_const_iter = email_vec::const_iterator;
using email_ref = Email&;
using email_const_ref = const Email&;

class MailBox
{
public:
	MailBox() = default;

	email_ref operator[](size_t index);
	email_const_ref operator[](size_t index)const;

	void push_back(Email email);

	vec_iter begin() noexcept;
	vec_iter end() noexcept;
	vec_const_iter begin()const noexcept;
	vec_const_iter end()const noexcept;

	void SortWho();
	void SortDate();
	void SortSubject();

private:
	email_vec emailList;
};

#endif // !MAILBOX_HPP
