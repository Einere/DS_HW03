#include "stdafx.h"
#include "my_heap.h"


My_heap::My_heap() {
	
	v.reserve(10);
	//allocate memory for vector
}

My_heap::~My_heap() {
	v.clear();
	//clear vector v
	vector<char>().swap(v);
	//fee vector v
}

void My_heap::insert(char input) {
	//insert input to vector v and reheapification
	if (v.empty()) {
		v.push_back(input);
	}
	else {
		v.push_back(input);
		index = v.size()-1;
		reheap_up(index);
	}
}

void My_heap::reheap_up(int index) {
	//reheapification upward, compare index with index's parent
	if ((int)floor((index - 1) / 2) < 0) {
		//if index is root (index has no parent)
		printf("index don't have parent\n");
	}
	else {
		//if index has parent
		if (v.at((int)floor((index - 1) / 2)) >= v.at(index)) { 
			//if parent's value >= index's value
			printf("parent >= index\n");  
			printf("parent : %c\n", v.at((int)floor((index - 1) / 2)));
			printf("index : %c\n", v.at(index));
		}
		else if (v.at((int)floor((index - 1) / 2)) < v.at(index)) {
			//if parent's value < index's value
			printf("parent < index\n");
			tmp = v.at((int)floor((index - 1) / 2));
			v.at((int)floor((index - 1) / 2)) = v.at(index);
			v.at(index) = tmp;
			printf("parent : %c\n", v.at((int)floor((index - 1) / 2)));
			printf("index : %c\n", v.at(index));

			reheap_up((int)floor((index - 1) / 2));
			//recursive reheapification upward
		}
		
	}
	return;
}

void My_heap::remove() {
	printf("size = %d\n", v.size());
	printf("capacity = %d\n", v.capacity());
	index = v.size() -1;
	v.at(0) = v.at(index);
	//copy last value to root
	//v.at(index) = NULL;
	v.pop_back();
	
	printf("size = %d\n", v.size());
	printf("capacity = %d\n", v.capacity());
	reheap_down(0);
}

void My_heap::reheap_down(int index) {
	//reheapification downward, compare index with index's children
	if ((index*2+1) >= v.size()) {
		//if index has no child
		printf("index has no child\n");
	}
	else if ((index*2+2) >= v.size()) {
		//if index only has left child
		printf("index only has left child\n");
		if (v.at(index) >= v.at(index * 2 + 1)) {
			//if index's value >= left child's value
			printf("index >= left\n");
		}
		else if (v.at(index) < v.at(index * 2 + 1)) {
			//if index's value < left child's value
			printf("index < left\n");
			tmp = v.at(index);
			v.at(index) = v.at(index * 2 + 1);
			v.at(index * 2 + 1) = tmp;
		}
	}
	else {
		//if index has children
		if (v.at(index) >= v.at(index * 2 + 1) && v.at(index) >= v.at(index * 2 + 2)) {
			//if index's value >= children's value
			printf("index >= children\n");
		}
		else {
			if (v.at(index * 2 + 1) <= v.at(index * 2 + 2)) {
				//if left child's value <= right child's value
				printf("left <= right\n");
				tmp = v.at(index);
				v.at(index) = v.at(index * 2 + 2);
				v.at(index * 2 + 2) = tmp;
				//swap index's value and right child's value
				reheap_down(index * 2 + 2);
				//recursive reheapification downward
			}
			else {
				//if left child's value > right child;s value
				printf("left > right\n");
				tmp = v.at(index);
				v.at(index) = v.at(index * 2 + 1);
				v.at(index * 2 + 1) = tmp;
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