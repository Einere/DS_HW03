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
	free_matrix();
	//free matrix
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

void My_heap::reheap_down(int index) {
	//reheapification downward, compare index with index's children
	//pre : index is child's index
	//post : maintain heap structure
	if (LEFT >= (int)v.size()) {
		//if index has no child
		printf("index has no child\n");
	}
	else if (RIGHT >= (int)v.size()) {
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

void My_heap::print_vector() {
	for (unsigned int i = 0; i < v.size(); i++) {
		printf("%c", v.at(i));
	}
	printf("\n");
}

void My_heap::set_menu(int menu) {
	this->menu = menu;
}

void My_heap::calculate() {
	//calculate row, column and allocate memory for m
	//pre : size() > 0
	//post : have allocated memory
	free_matrix();
	//free matrix
	depth = (int)floor(log2(v.size())) + 1;
	switch (menu) {
	case 1: 
		printf("v.size = %d\n", v.size());
		column = depth*2;
		printf("column = %d\n", column);
		row = (int)pow(2, depth) - 1;
		printf("row = %d\n", row);
		break;
	case 2:
		printf("v.size = %d\n", v.size());
		row = depth;
		printf("row = %d\n", row);
		column = (int)pow(2, depth) - 1;
		printf("column = %d\n", column);
		break;
	case 3:
		break;
	default: printf("select menu 1~3\n"); break;
	}
	//calculate row, column by menu
	matrix = new char*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new char[column];
		memset(matrix[i], NULL, column);
	}
	//allocate memory
	printf("allocate complete\n");
	printf("matrix[%d][%d]\n", row, column );
	return;
}

void My_heap::free_matrix() {
	//free matrix
	//pre : matrix isn't point null
	//post : clearly free matrix
	if (matrix != nullptr) {
		for (int i = 0; i < row; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

void My_heap::draw_heap() {
	//draw non-ratated heap
	//pre : 
	//post : copy vector to matrix's appropriate index
	calculate();
	//calculate row, column and allocate memory for matrix
	int i = 0, l = 0;
	int m = 0, n = 0;
	
	for (m = (row - 1 - i); m >= 0; i++, m = (row - 1 - i)) {
		l = 0;
		//printf("m = %d, i = %d\n", m, i);
		for (n = (int)pow(2, i) - 1; n < column; n += (int)pow(2, i + 1)) {
			//printf("n = %d, i = %d, l = %d, pow(2, i + 1) - 1 = %d \n", n, i, l, (int)pow(2, i + 1) - 1);
			if ((unsigned int)(pow(2, m) - 1 + l) < v.size()){
				//if (int)pow(2, m) - 1 + l) is accessable
				matrix[m][n] = v.at((int)pow(2, m) - 1 + l);
				printf("v.at() = %c\n", v.at((int)pow(2, m) - 1 + l));
				printf("matrix[%d][%d] = %c\n",m,n, matrix[m][n]);
			}
			l++;
			//for next node 
		}
	}
	printf("-----------------draw non-rotated heap complete\n");
	
	return;
}



void My_heap::draw_r_heap() {
	//draw rotated heap
	//pre : 
	//post : copy vector to matrix's appropriate index
	calculate();
	//calculate row, column and allocate memory for matrix
	int i = 0, l = 0;
	int m = 0, n = 0;

	for (n = (column - 1 - i); n >= 0; i++, n = (column - 1 - i*2)) {
		l = 0;
		//printf("n = %d, i = %d\n", n, i);
		for (m = row -1 - ((int)pow(2, i) - 1); m >=0; m -= (int)pow(2, i + 1)) {
			//printf("m = %d, i = %d, l = %d, pow(2, i + 1) - 1 = %d \n", m, i, l, (int)pow(2, i + 1) - 1);
			if ((unsigned int)(pow(2, depth - 1 - i) - 1 + l) < v.size()) {
				//if (int)(pow(2, depth-1-i) - 1 + l) accessable
				matrix[m][n] = v.at((int)pow(2, depth - 1 - i) - 1 + l);
				printf("v.at() = %c\n", v.at((int)pow(2, depth - 1 - i) - 1 + l));
				printf("matrix[%d][%d] = %c\n", m, n, matrix[m][n]);
			}
			l++;
			//for next node 
		}
	}
	printf("-----------------draw rotated heap complete\n");
	
	return;
}

void My_heap::print_heap() {
	//pre : exist matrix
	//post : print all heap to terminal
	int m = 0, n = 0;
	for (m = 0; m < row; m++) {
		for (n = 0; n < column; n++) {
			printf("%c", matrix[m][n]);
		}
		printf("\n");
	}
	printf("-----------------print heap complete\n");
	//print all heap
	return;
}