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
		index = v.size() - 1;
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
	index = v.size() - 1;
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
	printf("depth = %d", depth);
	int tmp_size = v.size();
	while (tmp_size > 7) {
		h_depth *= 2;
		tmp_size /= 4;
	}
	tmp_size = v.size();
	while (tmp_size > 1) {
		center = 2 * center + 1;
		tmp_size /= 4;
	}
	printf("h_depth = %d, center = %d\n", h_depth, center);
	//calculate h_depth
	switch (menu) {
	case 1:
		printf("v.size = %d\n", v.size());
		column = depth * 2;
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
		for (int o_depth = 1; o_depth <= depth; o_depth++) {
			if (o_depth == 1) {
				//set row, column to 1
				row = column = 1;
				continue;
			}
			if (o_depth % 2 == 1) {
				//if o_depth is odd number
				row = (row * 2) + 1;
			}
			else {
				//if o_depth is even number
				column = (column * 2) + 1;
			}
		}
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
	printf("matrix[%d][%d]\n", _msize(matrix) / sizeof(*matrix), _msize(matrix[0]));
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
			if ((unsigned int)(pow(2, m) - 1 + l) < v.size()) {
				//if (int)pow(2, m) - 1 + l) is accessable
				matrix[m][n] = v.at((int)pow(2, m) - 1 + l);
				printf("v.at() = %c\n", v.at((int)pow(2, m) - 1 + l));
				printf("matrix[%d][%d] = %c\n", m, n, matrix[m][n]);
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

	for (n = (column - 1 - i); n >= 0; i++, n = (column - 1 - i * 2)) {
		l = 0;
		//printf("n = %d, i = %d\n", n, i);
		for (m = row - 1 - ((int)pow(2, i) - 1); m >= 0; m -= (int)pow(2, i + 1)) {
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

void My_heap::r_draw_h_tree(int index, int i, int j, int hd, int U, int D, int R, int L) {
	if (index >= (int)v.size()) return;
	if (depth % 2 == 1) {
		matrix[i][j] = v.at(index);
		printf("self matrix[%d][%d] = %c\n", i, j, v.at(index));
		if (0 < PARENT && PARENT < v.size()) {
			for (int a = 1; matrix[i + a*V[U][0]][j + a*V[U][1]] == NULL; a++) {
				matrix[i + a*(V[U][0])][j + a*V[U][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[U][0], j + a*V[U][1], matrix[i + a*(V[U][0])][j + a*V[U][1]]);
			}
		}

		if (LEFT < v.size()) {
			//for index's left child
			matrix[i + hd*V[L][0]][j + hd*V[L][1]] = v.at(LEFT);
			printf("left matrix[%d][%d] = %c\n", i + hd*V[L][0], j + hd*V[L][1], v.at(LEFT));
			for (int a = 1; matrix[i + a*V[L][0]][j + a*V[L][1]] == NULL; a++) {
				matrix[i + a*V[L][0]][j + a*V[L][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[L][0], j + a*V[L][1], matrix[i + a*V[L][0]][j + a*V[L][1]]);
			}
			//print #
			My_heap::r_draw_h_tree(4 * index + 3, i + hd*(V[L][0] + V[U][0]), j + hd*(V[L][1] + V[U][1]), hd / 2, D, U, L, R);
			My_heap::r_draw_h_tree(4 * index + 4, i + hd*(V[L][0] + V[D][0]), j + hd*(V[L][1] + V[D][1]), hd / 2, U, D, R, L);
		}
		if (RIGHT < v.size()) {
			//for index's right child
			matrix[i + hd*V[R][0]][j + hd*V[R][1]] = v.at(RIGHT);
			printf("right matrix[%d][%d] = %c\n", i + hd*V[R][0], j + hd*V[R][1], v.at(RIGHT));
			for (int a = 1; matrix[i + a*V[R][0]][j + a*V[R][1]] == NULL; a++) {
				matrix[i + a*V[R][0]][j + a*V[R][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[R][0], j + a*V[R][1], matrix[i + a*V[R][0]][j + a*V[R][1]]);
			}
			//print #
			My_heap::r_draw_h_tree(4 * index + 5, i + hd*(V[R][0] + V[D][0]), j + hd*(V[R][1] + V[D][1]), hd / 2, U, D, R, L);
			My_heap::r_draw_h_tree(4 * index + 6, i + hd*(V[R][0] + V[U][0]), j + hd*(V[R][1] + V[U][1]), hd / 2, D, U, L, R);
		}
	}
	else {
		if (0 < PARENT && PARENT < v.size()) {
			for (int a = 1; matrix[i + a*V[U][0]][j + a*V[U][1]] == NULL; a++) {
				matrix[i + a*(V[U][0])][j + a*V[U][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[U][0], j + a*V[U][1], matrix[i + a*(V[U][0])][j + a*V[U][1]]);
			}
		}
		//print #
		matrix[i][j] = v.at(index);
		printf("self matrix[%d][%d] = %c\n", i, j, v.at(index));
		if (LEFT < v.size()) {
			//for index's left child
			matrix[i + hd*V[L][0]][j + hd*V[L][1]] = v.at(LEFT);
			printf("left matrix[%d][%d] = %c\n", i + hd*V[L][0], j + hd*V[L][1], v.at(LEFT));
			for (int a = 1; matrix[i + a*V[L][0]][j + a*V[L][1]] == NULL; a++) {
				matrix[i + a*V[L][0]][j + a*V[L][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[L][0], j + a*V[L][1], matrix[i + a*V[L][0]][j + a*V[L][1]]);
			}
			//print #
			My_heap::r_draw_h_tree(4 * index + 3, i + (hd*(V[L][0] + V[U][0]) / 2), j + hd*(V[L][1] + V[U][1]), hd / 2, D, U, L, R);
			My_heap::r_draw_h_tree(4 * index + 4, i + (hd*(V[L][0] + V[D][0]) / 2), j + hd*(V[L][1] + V[D][1]), hd / 2, U, D, R, L);
		}
		if (RIGHT < v.size()) {
			//for index's right child
			matrix[i + hd*V[R][0]][j + hd*V[R][1]] = v.at(RIGHT);
			printf("right matrix[%d][%d] = %c\n", i + hd*V[R][0], j + hd*V[R][1], v.at(RIGHT));
			for (int a = 1; matrix[i + a*V[R][0]][j + a*V[R][1]] == NULL; a++) {
				matrix[i + a*V[R][0]][j + a*V[R][1]] = '#';
				printf("between matrix[%d][%d] = %c\n", i + a*V[R][0], j + a*V[R][1], matrix[i + a*V[R][0]][j + a*V[R][1]]);
			}
			//print #
			My_heap::r_draw_h_tree(4 * index + 5, i + (hd*(V[R][0] + V[D][0]) / 2), j + hd*(V[R][1] + V[D][1]), hd / 2, U, D, R, L);
			My_heap::r_draw_h_tree(4 * index + 6, i + (hd*(V[R][0] + V[U][0]) / 2), j + hd*(V[R][1] + V[U][1]), hd / 2, D, U, L, R);
		}
	}
}

void My_heap::draw_h_tree() {
	index = v.size();
	if (depth % 2 == 1) {
		//depth is odd number
		My_heap::r_draw_h_tree(0, center, center, h_depth, 0, 1, 2, 3);
	}
	else {
		//depth is even number
		My_heap::r_draw_h_tree(0, center / 2, center, h_depth, 0, 1, 2, 3);
	}
	printf("-----------------draw h-tree complete\n");
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