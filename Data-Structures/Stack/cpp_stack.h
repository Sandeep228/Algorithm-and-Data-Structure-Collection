#ifndef _CPP_STACK_H_
#define _CPP_STACK_H_

template <class T>
class Stack
{
public:
	// core operations
	bool push(T item);
	T pop();

	// query operations
	const T& peek();
	bool is_full();
	bool is_empty();
	bool is_dynamically_sized();

	// constructor
	Stack(size_t initial_capacity = 10, bool use_dynamic_sizing = true);

private:
	bool m_dynamic_sizing_enabled;
	T *m_stack_array;
	size_t m_stack_item_count;
	size_t m_capacity;

};

#include "cpp_stack.cpp" // thanks, C++ templates! :) </sarcasm>
#endif