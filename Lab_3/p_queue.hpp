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

template<typename T, class Predicate>
inline T p_queue<T, Predicate>::pop()
{
	T pop_val = elements.back();
	elements.pop_back();
	return pop_val;
}

template<typename T, class Predicate>
inline void p_queue<T, Predicate>::push(T elem)
{
	elements.insert(std::lower_bound(elements.begin(), elements.end(), elem, comp), elem);
}

template<typename T, class Predicate>
inline int p_queue<T, Predicate>::size()
{
	return elements.size();
}

template<typename T, class Predicate>
inline bool p_queue<T, Predicate>::empty()
{
	return elements.empty();
}
