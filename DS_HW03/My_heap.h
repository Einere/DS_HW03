#pragma once
#define PARENT (int)floor((index - 1) / 2)
#define LEFT index*2+1
#define RIGHT index*2+2
class My_heap{
private:
	vector<char> v;
	int index = 0;
	//vector's index
	char tmp = NULL;
	string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int depth = 0;
	int h_depth = 1;
	//for tree
	int row = 0;
	int column = 0;
	char **matrix = nullptr;
	//for matrix
	int menu = 0;
	//for select draw function
	int V[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };
	int center = 0;
	//for h-tree

public:
	My_heap();
	~My_heap();
	void insert(char input);
	void reheap_up(int index);
	void reheap_down(int index);
	void remove();
	void print_vector();

	void set_menu(int menu);
	void calculate();
	void free_matrix();
	void draw_heap();
	void draw_r_heap();
	void r_draw_h_tree(int index, int i, int j, int H_depth, int U, int D, int R, int L);
	void draw_h_tree();
	void print_heap();

};

