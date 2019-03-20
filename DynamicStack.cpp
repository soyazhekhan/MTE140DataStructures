#include "DynamicStack.hpp"
#include <cstdlib>
#include <math.h>
#include <iostream>

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	capacity_ = 16;
	init_capacity_ = 16;
	items_ = new StackItem[capacity_];
	size_ = 0;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	if (capacity == 0)
	{
		capacity_ = init_capacity_ = 16;
	}
	else
	{
		capacity_ = init_capacity_ = capacity;
	}
	size_ = 0;
	items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
	delete[] items_;
	items_ = NULL;
	size_ = 0;
}

bool DynamicStack::empty() const
{
	return size_ == 0;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ == capacity_)
	{
		capacity_ *= 2;
		StackItem* temp = new StackItem[capacity_ ];
		for (int i = 0; i < size_; i++)
		{
			temp[i] = items_[i];
		}
		delete[] items_;
		items_ = temp;
	}
	items_[size_] = value;
	size_++;
}

StackItem DynamicStack::pop()
{
	if (empty())
	{
		return EMPTY_STACK;
	}
	StackItem popItem = items_[size_ - 1];
	size_--;
	if (size_ <= capacity_ / 4 && capacity_ / 2 >= init_capacity_)
	{
		capacity_ = ceil(capacity_ / 2);
		StackItem* temp = new StackItem[capacity_];
		for (int i = 0; i < size_; i++)
		{
			temp[i] = items_[i];
		}
		delete[] items_;
		items_ = temp;
	}
	return popItem;
}

StackItem DynamicStack::peek() const
{
	if (empty())
	{
		return EMPTY_STACK;
	}
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	if (empty())
	{
		return;
	}
	else if (size_ == 1)
	{
		std::cout << "([" + items_[0] << "])" << std::endl;
	}
	else
	{
		std::cout << "(";
		for (int i = size_ - 1; i >= 0; i--)
		{
			std::cout << "[" << items_[i] << "]";
			if (i != 0)
				std::cout << ",";
		}
		std::cout << ")" << std::endl;
	}
}