// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap];
	capacity_ = cap;
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete[] data_;
	data_ = NULL;
}

bool SequentialList::empty() const
{
	return size_ == 0;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	return size_ == capacity_;
}

void SequentialList::print() const
{
	if (size_ == 0)
		return;
	cout << "(";
	for (int i = 0; i < size_; i++)
		cout << "[" << data_[i] << "]" << " ";
	cout << ")";
}

bool SequentialList::insert_front(DataType val)
{
	if (full())
		return false;
	else
		for (int i = 0; i < size_; i++)
			data_[i + 1] = data_[i];
	data_[0] = val;
	size_++;
	return true;
}

bool SequentialList::remove_front()
{
	if (empty())
		return false;
	else
	{
		for (int i = 0; i < size_-1; i++)
			data_[i] = data_[i + 1];
		size_--;
	}
	return true;
}

bool SequentialList::insert_back(DataType val)
{
	if(full())
		return false;
	else
	{
		data_[size_] = val;
		size_++;
	}
	return true;
}

bool SequentialList::remove_back()
{
	if(empty())
		return false;
	else
		size_--;
	return true;

}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (full()||index > size_)
		return false;
	else
	{
		for (int i = index; i < size_;i++)
			data_[i+1] = data_[i];
		data_[index] = val;
		size_++;
	}
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	if(empty()|| index >= size_)
		return false;
	else
	{
		for (int i = index; i < size_-1; i++)
			data_[i] = data_[i+1];
	}
}

unsigned int SequentialList::search(DataType val) const
{
	if (empty())
		return size_;
	for (int i=0; i<size_;i++)
		if(data_[i] == val)
			return i;
	return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (empty())
		return NULL;
	else if(index >= size_)
		return data_[size_-1];
	else
		return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(empty()||index >= size_)
		return false;
	else
	{
		data_[index] = val;
	}
	return true;
}
