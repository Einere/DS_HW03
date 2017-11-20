#pragma once
#define PARENT (int)floor((index - 1) / 2)
#define LEFT index*2+1
#define RIGHT index*2+2
class My_heap
{
private:

	vector<char> v;
	//vector
	int index;
	//vector's index
	char tmp;
	string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row;
	//equal depth
	int column;
	char **matrix = nullptr;
	//for matrix

public:
	My_heap();
	~My_heap();
	void insert(char input);
	void reheap_up(int index);
	void remove();
	void reheap_down(int index);
	void print_vector();
	void calculate();
	void print_heap();
	void free_matrix();
};

