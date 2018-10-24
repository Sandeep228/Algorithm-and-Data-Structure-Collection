#include <exception> // for catching exceptions
#include <iostream>	 // for std:cout
#include <string>	 // for std::to_string()

#include "cpp_stack.h"

#ifdef _TEST_CPP_STACK_STANDALONE_
#define MAIN main
#else
#define MAIN test_cpp_stack
#endif

template <class T>
void test_stack_is_empty(Stack<T> stack)
{
	std::cout << "- Checking if the stack is empty\n";
	if (stack.is_empty())
		std::cout << "- - It is!\n";
	else
		std::cout << "- - It is not!\n";
}

template <class T>
void test_stack_is_full(Stack<T> stack)
{
	std::cout << "- Checking if the stack is full\n";
	if (stack.is_full())
		std::cout << "- - It is!\n";
	else
		std::cout << "- - It is not!\n";
}

void test_int_stack(size_t initial_capacity, bool dynamically_resize)
{
	Stack<int> stack(initial_capacity, dynamically_resize);

	std::cout << "- Checking if the stack is dynamically resizable\n";
	if (stack.is_dynamically_sized())
		std::cout << "- - It is!\n";
	else
		std::cout << "- - It is not!\n";

	
	test_stack_is_empty(stack);
	test_stack_is_full(stack);
	

	std::cout << "- Trying to pop an empty stack\n";
	try
	{
		int temp = stack.pop();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "- Trying to peek an empty stack\n";
	try
	{
		const int temp = stack.peek();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "- Attempting to add the numbers 0 through 10 inclusive to the stack\n";
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "- - Adding " << std::to_string(i) << std::endl;
		bool succeeded = stack.push(i);
		if (succeeded)
			std::cout << "- - - It worked!!\n";
		else
			std::cout << "- - - It failed!!\n";
	}

	test_stack_is_empty(stack);
	test_stack_is_full(stack);

	std::cout << "- Taking a peek at the item on top of the stack\n";
	int top = 0;
	bool got_val = false;
	try
	{
		top = stack.peek();
		got_val = true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	if (got_val)
		std::cout << "- - There is a " << std::to_string(top) << " on top of the stack!\n";

	std::cout << "- Attempting to pop eleven times!\n";
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "- - Pop attempt #" << std::to_string(i) << std::endl;
		try
		{
			int item = stack.pop();
			std::cout << "- - - Got " << std::to_string(item) << " from the stack!\n";
		}
		catch (std::exception& e)
		{
			std::cout << "- - - It failed! - "<< e.what() << std::endl;
		}
	}

	test_stack_is_empty(stack);
	test_stack_is_full(stack);

	std::cout << "Test complete!";
	
}

void test_static_sized_stack()
{
	std::cout << "--- Testing a statically sized stack! ---\n";
	test_int_stack(5, false);
	std::cout << std::endl << std::endl;
}

void test_dynamic_sized_stack()
{
	std::cout << "--- Testing a dynamically sized stack! ---\n";
	test_int_stack(1, true);
	std::cout << std::endl << std::endl;
}

void MAIN()
{
	test_static_sized_stack();
	test_dynamic_sized_stack();
	return;
}