// DSHW03.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "My_heap.h"

int main()
{
	My_heap h;

	h.insert('1');
	h.insert('2');
	h.insert('3');
	h.insert('4');
	h.insert('5');
	h.insert('6');
	h.insert('7');
	h.insert('8');
	h.insert('9');
	
	h.print_vector();
	/*
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.print_vector();
	*/

	printf("select menu\n");
	printf("1 : rotated heap\n");
	printf("2 : non-ratated heap\n");
	printf("3 : h-tree (not supported)");
	int menu;
	scanf_s("%d", &menu, sizeof(menu));
	h.set_menu(menu);
	h.calculate();

	
	switch (menu) {
	case 1: h.draw_r_heap(); break;
	case 2: h.draw_heap(); break;
	case 3: h.draw_h_tree(); break;
	}
	
	h.print_heap();
	


	system("pause");
	return 0;
    return 0;
}

