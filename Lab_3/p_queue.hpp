#ifndef P_QUEUE_HPP
#define P_QUEUE_HPP
#include <vector>
#include <functional>
#include <algorithm>

template<typename T, class Comparator = std::less<T>>
class p_queue
{
public:
	p_queue() = default;
	~p_queue() = default;

	T pop();
	void push(T elem);
	int size();
	bool empty();
private:
	Comparator comp;
	std::vector<T> elements;
};
#endif // !P_QUEUE_HPP

template<typename T, class Comparator>
inline T p_queue<T, Comparator>::pop()
{
	T pop_val = elements.back();
	elements.pop_back();
	return pop_val;
}

template<typename T, class Comparator>
inline void p_queue<T, Comparator>::push(T elem)
{
	elements.insert(std::lower_bound(elements.begin(), elements.end(), elem, comp), elem);
}

template<typename T, class Comparator>
inline int p_queue<T, Comparator>::size()
{
	return elements.size();
}

template<typename T, class Comparator>
inline bool p_queue<T, Comparator>::empty()
{
	return elements.empty();
}

