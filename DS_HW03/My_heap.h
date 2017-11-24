#pragma once
#define PARENT (int)floor((index - 1) / 2)
#define LEFT index*2+1
#define RIGHT index*2+2
class My_heap{
private:
	

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

