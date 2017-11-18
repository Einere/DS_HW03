#include "stdafx.h"
#include "my_heap.h"


My_heap::My_heap() {
	v.reserve(10);
	//allocate memory for vector
}

My_heap::~My_heap() {
	//pre : exist object
	//post : clearly free allocated memery
	v.clear();
	//clear vector v
	vector<char>().swap(v);
	//fee vector v
}

void My_heap::insert(char input) {
	//insert insert node having char input
	//pre : input type is char
	//post : maintain heap structure 
	if (v.empty()) {
		v.push_back(input);
	}
	else {
		v.push_back(input);
		index = v.size()-1;
		reheap_up(index);
		//reheapification
	}
}

void My_heap::reheap_up(int index) {
	//reheapification upward, compare index with index's parent
	//pre : index is child's index
	//post : make heap structure
	if (PARENT < 0) {
		//if index is root (index has no parent)
		printf("index don't have parent\n");
	}
	else {
		//if index has parent
		if (str.find(v.at(PARENT)) >= str.find(v.at(index))) { 
			//if parent's value >= index's value
			printf("parent >= index\n");  
			printf("parent : %c\n", v.at(PARENT));
			printf("index : %c\n", v.at(index));
		}
		else if (str.find(v.at(PARENT)) < str.find(v.at(index))) {
			//if parent's value < index's value
			printf("parent < index\n");
			tmp = v.at(PARENT);
			v.at(PARENT) = v.at(index);
			v.at(index) = tmp;
			printf("parent : %c\n", v.at(PARENT));
			printf("index : %c\n", v.at(index));

			reheap_up(PARENT);
			//recursive reheapification upward
		}
	}
	return;
}

void My_heap::remove() {
	//remove the largest node
	//pre : exist node
	//post : maintain heap structure
	if (v.empty()) return;
	//if don't exist node, do nothing
	printf("size = %d\n", v.size());
	printf("capacity = %d\n", v.capacity());
	index = v.size() -1;
	v.at(0) = v.at(index);
	//copy last value to root
	v.pop_back();
	
	printf("size = %d\n", v.size());
	printf("capacity = %d\n", v.capacity());
	reheap_down(0);
	//recursive reheapification downward
}

void My_heap::reheap_down(int index) {
	//reheapification downward, compare index with index's children
	//pre : index is child's index
	//post : maintain heap structure
	if (LEFT >= v.size()) {
		//if index has no child
		printf("index has no child\n");
	}
	else if (RIGHT >= v.size()) {
		//if index only has left child
		printf("index only has left child\n");
		if (str.find(v.at(index)) >= str.find(v.at(LEFT))) {
			//if index's value >= left child's value
			printf("index >= left\n");
		}
		else if (str.find(v.at(index)) < str.find(v.at(LEFT))) {
			//if index's value < left child's value
			printf("index < left\n");
			tmp = v.at(index);
			v.at(index) = v.at(LEFT);
			v.at(LEFT) = tmp;
		}
	}
	else {
		//if index has children
		if (str.find(v.at(index)) >= str.find(v.at(LEFT)) && str.find(v.at(index)) >= str.find(v.at(RIGHT))) {
			//if index's value >= children's value
			printf("index >= children\n");
		}
		else {
			if (str.find(v.at(LEFT)) <= str.find(v.at(RIGHT))) {
				//if left child's value <= right child's value
				printf("left <= right\n");
				tmp = v.at(index);
				v.at(index) = v.at(RIGHT);
				v.at(RIGHT) = tmp;
				//swap index's value and right child's value
				reheap_down(RIGHT);
				//recursive reheapification downward
			}
			else {
				//if left child's value > right child;s value
				printf("left > right\n");
				tmp = v.at(index);
				v.at(index) = v.at(LEFT);
				v.at(LEFT) = tmp;
				//swap index's value and left child's value
				reheap_down(index * 2 + 1);
				//recursive reheapification downward
			}
		}
	}
	return;
}

void My_heap::print_heap() {
	for (unsigned int i = 0; i < v.size(); i++) {
		printf("%c", v.at(i));
	}
	printf("\n");
}