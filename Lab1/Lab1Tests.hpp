#ifndef LAB1_TESTS_HPP
#define LAB1_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DoublyLinkedList.hpp"
#include "SequentialList.hpp"
#include <iostream>
using namespace std;

class SequentialListTest
{
public:
	bool test1()
	{
		unsigned int capacity = 5;
		SequentialList list(capacity);

		ASSERT_TRUE(list.size() == 0)
		ASSERT_TRUE(list.capacity() == capacity)
		ASSERT_TRUE(list.empty() == true)
		ASSERT_TRUE(list.full() == false)
		return true;
	}

	bool test2()
	{
		unsigned int capacity = 5;
		SequentialList list1(capacity);
		SequentialList list2(capacity);
		ASSERT_TRUE(list1.insert_front(100))
		ASSERT_TRUE(list2.insert_back(100))

		ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
		ASSERT_TRUE(list1.data_ != NULL)
		ASSERT_TRUE(list2.data_ != NULL)
		ASSERT_TRUE(list1.data_[0] == list2.data_[0] && list1.data_[0] == 100)
		return true;
	}

	bool test3()
	{
		unsigned int capacity = 5;
		SequentialList list(capacity);

		ASSERT_TRUE(list.insert_front(100))
		ASSERT_TRUE(list.insert_front(101))
		ASSERT_TRUE(list.remove_front())
		ASSERT_TRUE(list.remove_back())
		ASSERT_TRUE(list.search(100) == list.size_)

		for (int i = 0; i < capacity; i++)
		{
			ASSERT_TRUE(list.insert_back(i * 100))
		}

		unsigned int idx = 3;
		ASSERT_TRUE(list.search(list.select(idx)) == idx)
		ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
		ASSERT_TRUE(list.search(1000) == list.size())

		for (int i = 0; i < capacity; i++)
		{
			ASSERT_TRUE(list.select(i) == i * 100 && list.data_[i] == i * 100)
		}

		return true;
	}

	bool testAccessors()
	{
		std::cout << "TEST ACCESSORS \n";
		unsigned int capacity = 65536;
		SequentialList list(capacity);
		//test open list accessors
		ASSERT_TRUE(list.size() == 0);
		ASSERT_TRUE(list.capacity() == 65536);
		ASSERT_TRUE(list.empty());
		ASSERT_TRUE(!list.full());
		ASSERT_TRUE(list.select(0) == NULL);
		ASSERT_TRUE(list.select(-1) == NULL);
		ASSERT_TRUE(list.search(25) == list.size());
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;

		//add items
		for (int i = 0; i < 10; i++)
		{
			list.insert_front(9 - i);
		}

		//test accessors again
		ASSERT_TRUE(list.size() == 10);
		ASSERT_TRUE(list.capacity() == 65536);
		ASSERT_TRUE(!list.empty());
		ASSERT_TRUE(!list.full());
		ASSERT_TRUE(list.select(0) == 0);
		ASSERT_TRUE(list.select(-1) == list.select(100));
		ASSERT_TRUE(list.search(25) == list.size());
		ASSERT_TRUE(list.search(5) == 5);
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl << endl;

		return true;
	}

	//NOTE: THIS TEST NEEEDS CAPACITY TESTS
	bool testInserts()
	{
		std::cout << "TEST INSERTS \n";
		unsigned int capacity = 20;
		SequentialList list1(capacity);
		for (int i = 0; i < 10; i++)
			list1.insert_back(i);
		std::cout << "Printed Array: ";
		list1.print();
		std::cout << endl;

		//create new empty list
		SequentialList list(capacity);

		//use insert function
		ASSERT_TRUE(!list.insert(0, 5));
		//front
		ASSERT_TRUE(list.insert(3, 0));
		ASSERT_TRUE(list.insert(2, 0));
		//back
		ASSERT_TRUE(list.insert(6, list.size()));
		ASSERT_TRUE(list.insert(7, list.size()));
		//middle
		ASSERT_TRUE(list.insert(4, 2));
		ASSERT_TRUE(list.insert(5, 3));

		//front and backs
		ASSERT_TRUE(list.insert_front(1));
		ASSERT_TRUE(list.insert_front(0));

		ASSERT_TRUE(list.insert_back(8));
		ASSERT_TRUE(list.insert_back(9));

		ASSERT_TRUE(list.size() == 10);
		ASSERT_TRUE(list.select(0) == 0);
		ASSERT_TRUE(list.select(list.size()) == 9);

		//print
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl << endl;

		return true;
	}

	bool testRemoves()
	{
		std::cout << "TEST REMOVES \n";
		unsigned int capacity = 20;
		SequentialList list(capacity);
		for (int i = 0; i < 10; i++)
			list.insert_back(i);
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;

		//remove middles
		ASSERT_TRUE(list.remove(5));
		ASSERT_TRUE(list.remove(3));
		ASSERT_TRUE(list.remove(1));

		//remove ends
		ASSERT_TRUE(list.remove_front());
		ASSERT_TRUE(list.remove_front());

		ASSERT_TRUE(list.remove_back());
		ASSERT_TRUE(list.remove_back());

		//check status - should output 4,6,7
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;
		ASSERT_TRUE(
				list.select(0) == 4 &&
				list.select(1) == 6 &&
				list.select(2) == 7);

		//test ends of remove
		ASSERT_TRUE(list.remove(0));
		ASSERT_TRUE(list.remove(list.size() - 1));
		ASSERT_TRUE(!list.remove(list.size()));	//this tests if its one to far
		ASSERT_TRUE(list.select(0) == 6);
		ASSERT_TRUE(list.remove(0));

		//test empty limits for each
		ASSERT_TRUE(!list.remove(0));
		ASSERT_TRUE(!list.remove_front());
		ASSERT_TRUE(!list.remove_back());

		//print list -- should be empty
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl << endl;

		return true;
	}

	bool testReplace()
	{
		std::cout << "TEST REPLACE \n";
		unsigned int capacity = 20;
		SequentialList list(capacity);
		for (int i = 0; i < 10; i++)
			list.insert_front(i);
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;

		//test generics
		ASSERT_TRUE(list.replace(4, 44));
		ASSERT_TRUE(list.replace(1, 11));
		//endpoints
		ASSERT_TRUE(list.replace(0, 101));
		ASSERT_TRUE(list.replace(list.size() - 1, 99));

		//check limits
		ASSERT_TRUE(!list.replace(-1, 44));
		ASSERT_TRUE(!list.replace(list.size(), 69));

		//print
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;

		//change all values
		for (int i = 0; i < 10; i++)
		{
			ASSERT_TRUE(list.replace(i, i));
		}
		std::cout << "Printed Array: ";
		list.print();
		std::cout << endl;
		//check all values
		for (int i = 0; i < 10; i++)
		{
			ASSERT_TRUE(list.select(i) == i);
		}

		std::cout << endl << endl;

		return true;
	}

	bool testMaxSize()
	{
		unsigned int capacity = 65536;
		SequentialList list(capacity);
		for (int i = 0; i < 65536; i++)
		{
			list.insert_back(i);
		}

		//accessors
		ASSERT_TRUE(list.size() == 65536);
		ASSERT_TRUE(!list.empty());
		ASSERT_TRUE(list.full());
		ASSERT_TRUE(list.select(305) == 305);
		ASSERT_TRUE(list.select(0) == 0);
		ASSERT_TRUE(list.select(list.size()) == list.size() - 1);
		ASSERT_TRUE(list.search(305) == 305);
		ASSERT_TRUE(list.search(60000) == 60000);

		//mutators
		ASSERT_TRUE(!list.insert(-1, 45000));
		ASSERT_TRUE(!list.insert_front(-1));
		ASSERT_TRUE(!list.insert_back(-1));

		//adding and removing at limit
		ASSERT_TRUE(list.remove(5000));
		ASSERT_TRUE(list.insert(5000, 5000));

		ASSERT_TRUE(list.remove_front());
		ASSERT_TRUE(list.insert_front(0));

		ASSERT_TRUE(list.remove_back());
		ASSERT_TRUE(list.insert_back(list.capacity() - 1));

		//replace
		ASSERT_TRUE(list.replace(0, -1));
		ASSERT_TRUE(list.replace(0, 0));

		return true;
	}

};

//class DoublyLinkedListTest
//{
//public:
//	bool test1()
//	{
//		DoublyLinkedList list;
//		ASSERT_TRUE(list.size() == 0)
//		ASSERT_TRUE(list.empty() == true)
//		ASSERT_TRUE(list.full() == false)
//		ASSERT_TRUE(list.head_ == NULL)
//		ASSERT_TRUE(list.tail_ == NULL)
//		return true;
//	}
//
//	bool test2()
//	{
//		DoublyLinkedList list1, list2;
//		list1.insert_front(100);
//		list2.insert_back(100);
//
//		ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
//		ASSERT_TRUE(list1.head_ != NULL && list1.head_ == list1.tail_)
//		ASSERT_TRUE(list2.head_ != NULL && list2.head_ == list2.tail_)
//		ASSERT_TRUE(list1.head_->prev == NULL && list1.tail_->next == NULL)
//		ASSERT_TRUE(list2.head_->prev == NULL && list2.tail_->next == NULL)
//		ASSERT_TRUE(
//				list1.head_->value == list2.head_->value
//						&& list1.head_->value == 100)
//		return true;
//	}
//
//	bool test3()
//	{
//		DoublyLinkedList list;
//
//		ASSERT_TRUE(list.insert_front(100))
//		ASSERT_TRUE(list.insert_front(101))
//		ASSERT_TRUE(list.remove_front())
//		ASSERT_TRUE(list.remove_back())
//		ASSERT_TRUE(list.search(100) == list.size_)
//		ASSERT_TRUE(list.head_ == NULL && list.tail_ == NULL)
//
//		// List is [0, 100, ..., 400]
//		const int num_elems = 5;
//		for (int i = 0; i < num_elems; i++)
//		{
//			ASSERT_TRUE(list.insert_back(i * 100))
//		}
//
//		unsigned int idx = 3;
//		ASSERT_TRUE(list.search(list.select(idx)) == idx)
//		ASSERT_TRUE(list.search(1000) == list.size_)
//
//		// Check that the list has the right values
//		for (int i = 0; i < num_elems; i++)
//		{
//			ASSERT_TRUE(list.select(i) == i * 100)
//		}
//
//		ASSERT_TRUE(list.head_->prev == NULL && list.tail_->next == NULL)
//		return true;
//	}
//
//	bool test4()
//	{
//		DoublyLinkedList list;
//		for (int i = 0; i < 10; i++)
//			if (i % 2 == 0)
//				list.insert_front(i);
//			else
//				list.insert_back(i);
//
//		list.print();
//		return true;
//	}
//
//	bool testAccessors()
//	{
//		std::cout << "TEST ACCESSORS \n";
//		DoublyLinkedList list;
//		//test open list accessors
//		ASSERT_TRUE(list.size() == 0);
//		ASSERT_TRUE(list.capacity() == 65536);
//		ASSERT_TRUE(list.empty());
//		ASSERT_TRUE(!list.full());
//		ASSERT_TRUE(list.select(0) == NULL);
//		ASSERT_TRUE(list.select(-1) == NULL);
//		ASSERT_TRUE(list.search(25) == list.size());
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//
//		//add items
//		for (int i = 0; i < 10; i++)
//		{
//			list.insert_front(9 - i);
//		}
//
//		//test accessors again
//		ASSERT_TRUE(list.size() == 10);
//		ASSERT_TRUE(list.capacity() == 65536);
//		ASSERT_TRUE(!list.empty());
//		ASSERT_TRUE(!list.full());
//		ASSERT_TRUE(list.select(0) == 0);
//		ASSERT_TRUE(list.select(-1) == list.select(100));
//		ASSERT_TRUE(list.search(25) == list.size());
//		ASSERT_TRUE(list.search(5) == 5);
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl << endl;
//
//		return true;
//	}
//
//	//NOTE: THIS TEST NEEEDS CAPACITY TESTS
//	bool testInserts()
//	{
//		std::cout << "TEST INSERTS \n";
//		DoublyLinkedList list1;
//		for (int i = 0; i < 10; i++)
//			list1.insert_back(i);
//		std::cout << "Printed Array: ";
//		list1.print();
//		std::cout << endl;
//
//		//create new empty list
//		DoublyLinkedList list;
//
//		//use insert function
//		ASSERT_TRUE(!list.insert(0, 5));
//		//front
//		ASSERT_TRUE(list.insert(3, 0));
//		ASSERT_TRUE(list.insert(2, 0));
//		//back
//		ASSERT_TRUE(list.insert(6, list.size()));
//		ASSERT_TRUE(list.insert(7, list.size()));
//		//middle
//		ASSERT_TRUE(list.insert(4, 2));
//		ASSERT_TRUE(list.insert(5, 3));
//
//		//front and backs
//		ASSERT_TRUE(list.insert_front(1));
//		ASSERT_TRUE(list.insert_front(0));
//
//		ASSERT_TRUE(list.insert_back(8));
//		ASSERT_TRUE(list.insert_back(9));
//
//		ASSERT_TRUE(list.size() == 10);
//		ASSERT_TRUE(list.select(0) == 0);
//		ASSERT_TRUE(list.select(list.size()) == 9);
//
//		//print
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl << endl;
//
//		return true;
//	}
//
//	bool testRemoves()
//	{
//		std::cout << "TEST REMOVES \n";
//		DoublyLinkedList list;
//		for (int i = 0; i < 10; i++)
//			list.insert_back(i);
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//
//		//remove middles
//		ASSERT_TRUE(list.remove(5));
//		ASSERT_TRUE(list.remove(3));
//		ASSERT_TRUE(list.remove(1));
//
//		//remove ends
//		ASSERT_TRUE(list.remove_front());
//		ASSERT_TRUE(list.remove_front());
//
//		ASSERT_TRUE(list.remove_back());
//		ASSERT_TRUE(list.remove_back());
//
//		//check status - should output 4,6,7
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//		ASSERT_TRUE(
//				list.select(0) == 4 && list.select(1) == 6
//						&& list.select(2) == 7);
//
//		//test ends of remove
//		ASSERT_TRUE(list.remove(0));
//		ASSERT_TRUE(list.remove(list.size() - 1));
//		ASSERT_TRUE(!list.remove(list.size()));	//this tests if its one to far
//		ASSERT_TRUE(list.select(0) == 6);
//		ASSERT_TRUE(list.remove(0));
//
//		//test empty limits for each
//		ASSERT_TRUE(!list.remove(0));
//		ASSERT_TRUE(!list.remove_front());
//		ASSERT_TRUE(!list.remove_back());
//
//		//test pointers
//		ASSERT_TRUE(list.head_ == list.tail_ && list.head_ == NULL);
//
//		//print list -- should be empty
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl << endl;
//
//		return true;
//	}
//
//	bool testReplace()
//	{
//		std::cout << "TEST REPLACE \n";
//		DoublyLinkedList list;
//		for (int i = 0; i < 10; i++)
//			list.insert_front(i);
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//
//		//test generics
//		ASSERT_TRUE(list.replace(4, 44));
//		ASSERT_TRUE(list.replace(1, 11));
//		//endpoints
//		ASSERT_TRUE(list.replace(0, 101));
//		ASSERT_TRUE(list.replace(list.size() - 1, 99));
//
//		//check limits
//		ASSERT_TRUE(!list.replace(-1, 44));
//		ASSERT_TRUE(!list.replace(list.size(), 69));
//
//		//print
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//
//		//change all values
//		for (int i = 0; i < 10; i++)
//		{
//			ASSERT_TRUE(list.replace(i, i));
//		}
//		std::cout << "Printed Array: ";
//		list.print();
//		std::cout << endl;
//		//check all values
//		for (int i = 0; i < 10; i++)
//		{
//			ASSERT_TRUE(list.select(i) == i);
//		}
//
//		std::cout << endl << endl;
//
//		return true;
//	}
//
//	bool testMaxSize()
//	{
//		DoublyLinkedList list;
//		for (int i = 0; i < list.CAPACITY; i++)
//		{
//			list.insert_back(i);
//		}
//
//		//accessors
//		ASSERT_TRUE(list.size() == list.CAPACITY && list.size() == 65536);
//		ASSERT_TRUE(!list.empty());
//		ASSERT_TRUE(list.full());
//		ASSERT_TRUE(list.select(305) == 305);
//		ASSERT_TRUE(list.select(0) == 0);
//		ASSERT_TRUE(list.select(list.size()) == list.size() - 1);
//		ASSERT_TRUE(list.search(305) == 305);
//		ASSERT_TRUE(list.search(60000) == 60000);
//
//		//mutators
//		ASSERT_TRUE(!list.insert(-1, 45000));
//		ASSERT_TRUE(!list.insert_front(-1));
//		ASSERT_TRUE(!list.insert_back(-1));
//
//		//adding and removing at limit
//		ASSERT_TRUE(list.remove(5000));
//		ASSERT_TRUE(list.insert(5000, 5000));
//
//		ASSERT_TRUE(list.remove_front());
//		ASSERT_TRUE(list.insert_front(0));
//
//		ASSERT_TRUE(list.remove_back());
//		ASSERT_TRUE(list.insert_back(list.CAPACITY - 1));
//
//		//replace
//		ASSERT_TRUE(list.replace(0, -1));
//		ASSERT_TRUE(list.replace(0, 0));
//
//		//check pointers
//		ASSERT_TRUE(list.head_ != NULL && list.tail_ != NULL);
//
//		return true;
//	}
//
//};

#endif
