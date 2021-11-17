#ifndef P_QUEUE_HPP
#define P_QUEUE_HPP

#include <functional>
#include <vector>

template<typename T, class Predicate = std::less<>>
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
	std::vector<T> my_queue;
};
#endif // !P_QUEUE_HPP

template<typename T, class Predicate>
inline T p_queue<T, Predicate>::pop()
{
	T pop_val = my_queue.back();
	my_queue.pop_back();
	return pop_val;
}

template<typename T, class Predicate>
inline void p_queue<T, Predicate>::push(T elem)
{
	Predicate predicate;

	my_queue.insert(std::lower_bound(my_queue.begin(), my_queue.end(), elem, predicate), elem);
}

template<typename T, class Predicate>
inline int p_queue<T, Predicate>::size()
{
	return my_queue.size();
}

template<typename T, class Predicate>
inline bool p_queue<T, Predicate>::empty()
{
	return my_queue.empty();
}
