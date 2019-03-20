#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    SequentialListTest seq_test;
    //DoublyLinkedListTest linked_test;


    bool seq_test1_passed = seq_test.test1();
    bool seq_test2_passed = seq_test.test2();
    bool seq_test3_passed = seq_test.test3();
    bool seq_testAccessors_passed = seq_test.testAccessors();
    bool seq_testInserts_passed = seq_test.testInserts();
    bool seq_testRemoves_passed = seq_test.testRemoves();
    bool seq_testReplace_passed = seq_test.testReplace();
    bool seq_testMaxSize_passed = seq_test.testMaxSize();


    cout << "---Sequential List Tests---" << endl;
    cout << "Test1: " << get_status_str(seq_test1_passed) << endl;
    cout << "Test2: " << get_status_str(seq_test2_passed) << endl;
    cout << "Test3: " << get_status_str(seq_test3_passed) << endl;
    cout << "TestACCESS: " << get_status_str(seq_testAccessors_passed) << endl;
	cout << "TestINSERT: " << get_status_str(seq_testInserts_passed) << endl;
    cout << "TestREMOVE: " << get_status_str(seq_testRemoves_passed) << endl;
    cout << "TestREPLACE: " << get_status_str(seq_testReplace_passed) << endl;
    cout << "TestMaxSize: " << get_status_str(seq_testMaxSize_passed) << endl;
    cout << endl;


//    //linked lists
//    bool linked_test1_passed = linked_test.test1();
//    bool linked_test2_passed = linked_test.test2();
//    bool linked_test3_passed = linked_test.test3();
//    bool linked_test4_passed = linked_test.test4();
//    bool linked_testAccessors_passed = linked_test.testAccessors();
//    bool linked_testInserts_passed = linked_test.testInserts();
//    bool linked_testRemoves_passed = linked_test.testRemoves();
//    bool linked_testReplace_passed = linked_test.testReplace();
//    bool linked_testMaxSize_passed = linked_test.testMaxSize();

//
//    cout << "---Linked List Tests---" << endl;
//	cout << "Test1: " << get_status_str(linked_test1_passed) << endl;
//	cout << "Test2: " << get_status_str(linked_test2_passed) << endl;
//	cout << "Test3: " << get_status_str(linked_test3_passed) << endl;
//    cout << "TestACCESS: " << get_status_str(linked_testAccessors_passed) << endl;
//	cout << "TestINSERT: " << get_status_str(linked_testInserts_passed) << endl;
//    cout << "TestREMOVE: " << get_status_str(linked_testRemoves_passed) << endl;
//    cout << "TestREPLACE: " << get_status_str(linked_testReplace_passed) << endl;
//    cout << "TestMaxSize: " << get_status_str(linked_testMaxSize_passed) << endl;

}
