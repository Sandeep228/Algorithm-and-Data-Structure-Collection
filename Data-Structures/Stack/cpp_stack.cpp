// DO NOT COMPILE THIS FILE DIRECTLY.
// Due to weird idiosyncrasies of template classes in C++, this file is included by and compiled within cpp_stack.h.

#include "cpp_stack.h"


/// size_t initial capacity: sets the initial size of the stack. default is 10.
/// bool use_dynamic_sizing: if true, the stack grows when it reaches its capacity.  default is true.
template <class T>
Stack<T>::Stack(size_t initial_capacity /*= 10*/, bool use_dynamic_sizing /*= true*/)
{
	if (initial_capacity <= 0)
	{
		initial_capacity = 10;
	}

	m_stack_array = new T[initial_capacity];
	m_capacity = initial_capacity;
	m_stack_item_count = 0;
	m_dynamic_sizing_enabled = use_dynamic_sizing;
}


/// input: item of type T, which will be pushed to the top of the stack
/// output: true if the item was successfully pushed to the stack.  false otherwise.
template <class T>
bool Stack<T>::push(T item)
{
	if (m_stack_item_count == m_capacity)
	{
		if (!is_dynamically_sized())
		{
			return false;
		}

		T *replacement_array = new T[m_capacity * 2];
		for (size_t i = 0; i < m_capacity; i++)
		{
			replacement_array[i] = m_stack_array[i];
		}

		delete[] m_stack_array;
		m_stack_array = replacement_array;
		m_capacity *= 2;
	}

	m_stack_array[m_stack_item_count] = item;
	m_stack_item_count++;
	
	return true;
}


/// input: <void>
/// output: item of type T, which was removed from the top of the stack.
/// throws: std::runtime_error when there is nothing on the stack.
template <class T>
T Stack<T>::pop()
{
	if (m_stack_item_count <= 0)
		throw std::runtime_error("There is nothing on the stack, pop failed!");

	m_stack_item_count--;
	return m_stack_array[m_stack_item_count];
}


/// input: <void>
/// output: const reference of item of type T, the item currently at the top of the stack
/// throws: std::runtime_error when there is nothing on the stack.
template <class T>
const T& Stack<T>::peek()
{
	if (m_stack_item_count <= 0)
		throw std::runtime_error("There is nothing on the stack, peek failed!");
	
	return m_stack_array[m_stack_item_count - 1];
}


/// input: <void>
/// output: true if the stack is full AND not dynamically resizeable.  false otherwise.
template <class T>
bool Stack<T>::is_full()
{
	if (m_stack_item_count == m_capacity && !is_dynamically_sized())
		return true;
	
	return false;
}


/// input: <void>
/// output: true if the stack contains 0 or less items.  false otherwise.
template <class T>
bool Stack<T>::is_empty()
{
	if (m_stack_item_count <= 0)
	{
		return true;
	}

	return false;
}


/// input: <void>
/// output: true if the stack is dynamically resizable.  false otherwise.
template <class T>
bool Stack<T>::is_dynamically_sized()
{
	return m_dynamic_sizing_enabled;
}

