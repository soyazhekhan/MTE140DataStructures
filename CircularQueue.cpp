#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	capacity_ = 16;
	items_ = new QueueItem[capacity_];
	size_ = 0;
	tail_ = 0;
	head_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	if (capacity == 0)
	{
		capacity_ = 16;
	}
	else
	{
		capacity_ = capacity;
	}
	items_ = new QueueItem[capacity_];
	size_ = 0;
	tail_ = 0;
	head_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete[] items_;
	items_ = NULL;
	tail_ = head_ = 0;
	size_ = 0;
}

bool CircularQueue::empty() const
{
	return size_ == 0;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (full())
		return false;
	else
	{
		items_[tail_] = value;
		tail_ = (tail_ + 1) % capacity_;
		size_++;
	}
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if (empty())
		return EMPTY_QUEUE;
	QueueItem deqItem = items_[head_];
	head_ = (head_ + 1) % capacity_;
	size_--;
	return deqItem;
}

QueueItem CircularQueue::peek() const
{
	if (empty())
		return EMPTY_QUEUE;
	else
	{
		return items_[head_];
	}
}

void CircularQueue::print() const
{
	if (empty())
	{
		return;
	}
	else if (size_ == 1)
	{
		std::cout << "([" + items_[head_] << "])" << std::endl;
	}
	else
	{
		std::cout << "(";
		for (int i = head_; i < tail_; i++)
		{
			std::cout << "[" << items_[i] << "]";
			if (i != tail_ - 1)
				std::cout << ",";
		}
		std::cout << ")" << std::endl;
	}
}
