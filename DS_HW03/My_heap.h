#pragma once

class My_heap
{
private:
	vector<char> v;
	//vector
	//vector<char>::iterator iter;
	//iterator for vector
	int index;
	//vector's index
	char tmp;
	string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	My_heap();
	~My_heap();
	void insert(char input);
	void reheap_up(int index);
	void remove();
	void reheap_down(int index);
	void print_heap();
};

