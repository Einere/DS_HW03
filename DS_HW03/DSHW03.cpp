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
	h.insert('a');
	h.insert('b');
	h.insert('c');
	h.insert('A');
	h.insert('B');
	h.insert('C');
	h.print_heap();
	
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.remove();
	h.print_heap();

	system("pause");
	return 0;
    return 0;
}

