#include "DoublyLinkedList.hpp"
#include <cstdlib>
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	this -> next = NULL;
	this -> prev = NULL;
	this -> value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	this -> head_ = NULL;
	this -> tail_ = NULL;
	this -> size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if (head_ == NULL) {
		return;
	} else {
		Node* node1 = head_;
		Node* node2 = node1 -> next;	//partially redundant, really only need declaration
		while (node1 != NULL) {
			node2 = node1 -> next;
			delete node1;
			node1 = node2;
		}
	}

	//set pointers to NULL
	head_ = NULL;
	tail_ = NULL;
}

bool DoublyLinkedList::empty() const
{
	//check size just in case
	return head_ == NULL && size_ == 0;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	//pretty useless function, capacity is const
	return CAPACITY;
}

void DoublyLinkedList::print() const
{
	//iterate each element, in an array with pointer fashion
	//if list is empty, return nothing
	if (head_ == NULL) {
		return;
	} else if (size_ == 1) {
		std::cout << "([" + head_->value << "])" << std::endl;
	} else {
		std::cout << "(";
		Node* node = head_;

		while (node != NULL) {
			std::cout << "[" << node-> value << "]";
			node = node -> next;
			if (node != NULL)
				std::cout << "->";
		}
		std::cout << ")" << std::endl;
	}
}

//when would this return false? Maxed out list?
bool DoublyLinkedList::insert_front(DataType value)
{

	if (size_ == CAPACITY) {
		return false;
	} else if (head_ == NULL) {
		Node* frontNode = new Node(value);
		head_ = frontNode;
		tail_ = frontNode;
	} else {
		Node* frontNode = new Node(value);
		head_->prev = frontNode;
		frontNode->next = head_;
		head_ = frontNode;
	}
	//update size and return true if base case was surpassed
	size_++;
	return true;

}

bool DoublyLinkedList::remove_front()
{
	//consider empty list
	if (head_ == NULL) {
		return false;
	} else if (head_-> next == NULL) {
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	} else {
		head_ = head_ -> next;
		delete head_ -> prev;
		head_ -> prev = NULL;
	}
	//update list size and return
	size_--;
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if (size_ == CAPACITY)
		return false;
	else if (head_ == NULL) {
		Node* backNode = new Node(value);
		head_ = backNode;
		tail_ = backNode;
	} else {
		Node* backNode = new Node(value);
		//add element to tail, set new tail
		tail_ -> next = backNode;
		backNode -> prev = tail_;
		tail_ = backNode;
	}
	//update list size and return
	size_++;
	return true;
}

bool DoublyLinkedList::remove_back()
{
	if(head_ == NULL) {
		return false;
	} else if (head_ -> next == NULL) {
		delete head_;
		head_ = NULL;
		tail_ = NULL;
	} else {
		//set tail to second last element, delete that last element
		tail_ = tail_->prev;
		delete tail_->next;
		tail_->next = NULL;
	}
	//update list size and return
	size_ --;
	return true;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	//check if index is in bounds using size - shoudln't have to worry about it exceeding CAP
	if (index > size_ || size_ == CAPACITY) {
		return false;
	} else if (index == 0) {
		return insert_front(value);
	} else if (index == size_) {
		return insert_back(value);
	} else {
		Node* newNode = new Node(value);
		Node* indexNode = head_;

		//insert element into given index, move pointers of prev and next
		for (int i=0; i < index; i++)
			indexNode = indexNode-> next;

		Node* prevNode = indexNode -> prev;
		Node* nextNode = indexNode;

		prevNode -> next = newNode;
		newNode -> prev = prevNode;

		nextNode -> prev = newNode;
		newNode -> next = nextNode;
	}
	//update size and return
	size_++;
	return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	//check if index is in bounds using size - shoudln't have to worry about it exceeding CAP
	//for remove u need to make sure it's within indices
	//check head as well as last resort
	if (index > size_-1 || head_==NULL) {
		return false;
	} else if (index == 0) {
		return remove_front();
	} else if (index == size_-1) {
		return remove_back();
	} else {
		Node* indexNode = head_;

		for (int i=0; i < index; i++)
			indexNode = indexNode-> next;

		Node* prevNode = indexNode -> prev;
		Node* nextNode = indexNode -> next;

		delete indexNode;
		indexNode = NULL;

		prevNode -> next = nextNode;
		nextNode -> prev = prevNode;
	}

	//update size and return
	size_--;
	return true;

}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node* searchNode = head_;
	int index = 0;

	while (searchNode != NULL) {
		if (searchNode -> value == value)
			return index;
		searchNode = searchNode -> next;
		index ++;
	}
	//if nothing is found
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	//check if index is in bounds using size, return value of last element
	if (head_ == NULL)
		return NULL;
	else if (index > size_-1)
		return tail_->value;

	Node* searchNode = head_;

	for (int i=0; i<index; i++)
		searchNode = searchNode -> next;

	return searchNode -> value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	//check if index is in bounds using size
	if (index > size_-1)
		return false;

	//find node to replace
	Node* replaceNode = getNode(index);

	replaceNode -> value = value;
	return true;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	//check if index is in bounds using size
	if (index > size_-1)
		return NULL;

	//find node
	Node* searchNode = head_;
	for (int i=0; i<index; i++)
		searchNode = searchNode->next;

	return searchNode;

}
bool DoublyLinkedList::full() const
{
	return size_ == CAPACITY;
}
