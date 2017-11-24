#include "stdafx.h"
#include "My_heap.h"

int main() {
	My_heap h;
	char tmp_str[100];
	ifstream fs("input.txt");
	fs.getline(tmp_str, 3);
	int cmd_num = atoi(tmp_str);
	cout << cmd_num << endl;
	std::streambuf * pbuf = fs.rdbuf();
	while (pbuf->sgetc() != EOF && cmd_num != 0) {
		if (pbuf->sgetc() == 'I') {
			pbuf->sbumpc();
			pbuf->sbumpc();
			printf("h.insert(%c);\n", pbuf->sgetc());
			h.insert(pbuf->sbumpc());
			pbuf->sbumpc();
			cmd_num--;
		}
		else if (pbuf->sgetc() == 'D') {
			pbuf->sbumpc();
			pbuf->sbumpc();
			cout << "h.remove();" << endl;
			h.remove();
			cmd_num--;
		}
	}
	fs.close();

	h.print_vector();

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
}