////////////////////////////////////////////////////////////
// CIS 554 Grading for HW1                                //
// Fall 2019                                              //
// Abel Armede - agarmede@syr.edu                         //
////////////////////////////////////////////////////////////

#include "pch.h"
#include "../Tester/HW1.h"
#include "marks.h" 
#include <fstream>

/////////////////////////////////////////////////////
// Tessting 
// group() 15 marks.
/////////////////////////////////////////////////////
TEST(TestGroup, group_an_empty_list) {
	DoublyLinkedList dc;
	dc.correct_group();

	DoublyLinkedList d;
	d.group();
	
	if (dc.isSorted(d)) {
		cout << "Group an empty list: correct + 1" << endl << Marks::addRMark(GROUP_AN_EMPTY_LIST);
		//myfile << "Remove from empty list: correct +1" << endl; 
	}
	else {
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group an empty list: not correct (1)" << endl;
	}
}


TEST(TestGroup, group_a_small_grouped_list) {
	DoublyLinkedList dc({ 1,1,1,1 });
	dc.correct_group();

	DoublyLinkedList d({ 1,1,1,1 });
	d.group();

	
	if (dc.isSorted(d)) {
		cout << "Group a small grouped list: correct +2" << endl << Marks::addRMark(GROUP_A_SMALL_GROUPED_LIST);
		//myfile << "Remove from empty list: correct +1" << endl;
	}
	else {
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group a small grouped list: not correct (2)" << endl;
	}
}

TEST(TestGroup, group_random_list) {
	DoublyLinkedList dc({ 2,2,5,5,5,3,2,3,3,2,5,7,1,7,7 });
	dc.correct_group();

	Node::clearNodes();
	DoublyLinkedList d({ 2,2,5,5,5,3,2,3,3,2,5,7,1,7,7 });
	d.group();


	if (dc.isSorted(d)) {
		cout << "Group random list : correct +3" << endl << Marks::addRMark(GROUP_RANDOM_LIST);
		//std::cout << "\n " << " Created:  " << Node::elementCreated << " Deleted: " << Node::elementDeleted << " "<<endl;
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 15) << "Memory Leak -1" << Marks::deductRMark(MEMORY_LEAK);
		EXPECT_TRUE(Node::elementCreated < 16) << "Creating New Node Data Structure -2" << Marks::deductRMark(ADDED_MORE_NODES);
	}
	else if (dc.compareForward(d)) {
		cout << "Group random list - Forward : correct +2" << endl << Marks::addRMark(2);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 15) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 16) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group random list - Backward : not correct (lost 1)" << endl;
	}
	else if (dc.compareBackward(d)) {
		cout << "Group random list - Backward : correct +2" << endl << Marks::addRMark(2);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 15) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 16) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group random list - Forward : not correct (lost 1)" << endl;
	}
	else {
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group random list : not correct (4)" << endl;
	}
}

TEST(TestGroup, group_from_tail) {
	DoublyLinkedList dc({ 9,2,5,5,3,5,7,3,2,9,3,2,5,7,1,5,2,2,9 });
	dc.correct_group();

	Node::clearNodes();
	DoublyLinkedList d({ 9,2,5,5,3,5,7,3,2,9,3,2,5,7,1,5,2,2,9 });
	d.group();
	
	if (dc.isSorted(d)) {
		cout << "Group froom tail : correct +4" << endl << Marks::addRMark(GROUP_FROM_TAIL);
		//std::cout << "\n " << " Created:  " << Node::elementCreated << " Deleted: " << Node::elementDeleted << " "<<endl;
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 19) << "Memory Leak -1" << Marks::deductRMark(MEMORY_LEAK);
		EXPECT_TRUE(Node::elementCreated < 20) << "Creating New Node Data Structure -3" << Marks::deductRMark(3);
	}
	else if (dc.compareForward(d)) {
		cout << "Group froom tail - Forward : correct +2" << endl << Marks::addRMark(2);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 19) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 20) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group froom tail - Backward : not correct (lost 2)" << endl;
	}
	else if (dc.compareBackward(d)) {
		cout << "Group froom tail - Backward : correct +2" << endl << Marks::addRMark(2);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 19) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 20) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group froom tail - Forward : not correct (lost 2)" << endl;
	}
	else {
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group from tail : not correct (4)" << endl;
	}
}

TEST(TestGroup, group_large_list) {
	DoublyLinkedList dc({ 7,8,2,1,5,12,13,1,6,8,9,1,0,7,9,3,2,2,1,3,5,9,6,13,11,12,5,1,4,12,4,17,2,1,6,8,19,21,7 });
	dc.correct_group();

	Node::clearNodes();
	DoublyLinkedList d({ 7,8,2,1,5,12,13,1,6,8,9,1,0,7,9,3,2,2,1,3,5,9,6,13,11,12,5,1,4,12,4,17,2,1,6,8,19,21,7 });
	d.group();
	
	if (dc.isSorted(d)) {
		cout << "Group large list : correct +5" << endl << Marks::addRMark(GROUP_LARGE_LIST);
		//std::cout << "\n " << " Created:  " << Node::elementCreated << " Deleted: " << Node::elementDeleted << " "<<endl;
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 39) << "Memory Leak -1" << Marks::deductRMark(MEMORY_LEAK);
		EXPECT_TRUE(Node::elementCreated < 40) << "Creating New Node Data Structure -4" << Marks::deductRMark(4);
	}
	else if (dc.compareForward(d)) {
		cout << "Group large list - Forward : correct +2" << endl << Marks::addRMark(2);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 39) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 40) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group large list - Backward : not correct (lost 3)" << endl;
	}
	else if (dc.compareBackward(d)) {
		cout << "Group large list - Backward : correct +3" << endl << Marks::addRMark(3);
		EXPECT_TRUE((Node::elementCreated - Node::elementDeleted) <= 39) << "Memory Leak -1" << Marks::deductRMark(1);
		EXPECT_TRUE(Node::elementCreated < 40) << "Creating New Node Data Structure -1" << Marks::deductRMark(1);
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group large list - Forward : not correct (lost 2)" << endl;
	}
	else {
		std::cout << "\n Student's result: ";
		d.printForward();
		d.printBackward();

		std::cout << "\n Correct result: ";
		dc.printForward();
		dc.printBackward();
		cout << endl;
		EXPECT_TRUE(false) << "\n Group large list : not correct (5)" << endl;
	}
}

//TEST(Final_Mark) {
//	cout << endl;
//	cout << "The Final Mark is :" << Marks::Rmarks + Marks::Mmarks << endl;
//}
