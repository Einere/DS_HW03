#include "stdafx.h"
#include "my_heap.h"


My_heap::My_heap() {
	
	priority['0'] = 0; priority['1'] = 1; priority['2'] = 2; priority['3'] = 3; priority['4'] = 4; priority['5'] = 5;
	priority['6'] = 6; priority['7'] = 7; priority['8'] = 8; priority['9'] = 9; priority['a'] = 10; priority['b'] = 11;
	priority['c'] = 12; priority['d'] = 13; priority['e'] = 14; priority['f'] = 15; priority['g'] = 16; priority['h'] = 17;
	priority['i'] = 18; priority['j'] = 19; priority['k'] = 20; priority['l'] = 21; priority['m'] = 22; priority['n'] = 23;
	priority['o'] = 24; priority['p'] = 25; priority['q'] = 26; priority['r'] = 27; priority['s'] = 28; priority['t'] = 29;
	priority['u'] = 30; priority['v'] = 31; priority['w'] = 32; priority['x'] = 33; priority['y'] = 34; priority['z'] = 35;
	priority['A'] = 36; priority['B'] = 37; priority['C'] = 38; priority['D'] = 39; priority['E'] = 40; priority['F'] = 41;
	priority['G'] = 42; priority['H'] = 43; priority['I'] = 44; priority['J'] = 45; priority['K'] = 46; priority['L'] = 47;
	priority['M'] = 48; priority['N'] = 49; priority['O'] = 50; priority['P'] = 51; priority['Q'] = 52; priority['R'] = 53;
	priority['S'] = 54; priority['T'] = 55; priority['U'] = 56; priority['V'] = 57; priority['W'] = 58; priority['X'] = 59;
	priority['Y'] = 60; priority['Z'] = 61;
	//priority mapping

	v.reserve(10);
	//allocate memory for vector
}

My_heap::~My_heap() {
	priority.clear();
	//clear map priority
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
	index = v.size();
	v.at(0) = v.at(index);
	v.at(index) = NULL;
	//copy last value to root
	reheap_down(0);
}

void My_heap::reheap_down(int index) {
	//reheapification downward, compare index with index's children
	if (v.at(index * 2 + 1) == NULL) {
		//if index has no child
		return;
	}
	else if (v.at(index * 2 + 2) == NULL) {
		//if index only has left child
		if (v.at(index) >= v.at(index * 2 + 1)) {
			//if index's value >= left child's value
			return;
		}
		else {
			//if index's value < left child's value
			tmp = v.at(index);
			v.at(index) = v.at(index * 2 + 1);
			v.at(index * 2 + 1) = tmp;
		}
	}
	else {
		//if index has children
		if (v.at(index) >= v.at(index * 2 + 1) && v.at(index) >= v.at(index * 2 + 2)) {
			//if index's value >= children's value
			return;
		}
		else {
			if (v.at(index * 2 + 1) <= v.at(index * 2 + 2)) {
				//if left child's value <= right child's value
				tmp = v.at(index);
				v.at(index) = v.at(index * 2 + 2);
				v.at(index * 2 + 2) = tmp;
				//swap index's value and right child's value
				reheap_down(index * 2 + 2);
				//recursive reheapification downward
			}
			else {
				//if left child's value > right child;s value
				tmp = v.at(index);
				v.at(index) = v.at(index * 2 + 1);
				v.at(index * 2 + 1) = tmp;
				//swap index's value and left child's value
				reheap_down(index * 2 + 1);
				//recursive reheapification downward
			}
		}
	}
}

void My_heap::print_heap() {
	for (unsigned int i = 0; i < v.size(); i++) {
		printf("%c", v.at(i));
	}
	printf("\n");
}