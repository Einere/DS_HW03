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

	h.print_heap();
	
	system("pause");
	return 0;
    return 0;
}

