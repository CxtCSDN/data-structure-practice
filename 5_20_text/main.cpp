#define _CRT_SECURE_NO_WARNINGS 1

#include"stack_list.h"

int main()
{
	Stack St;
	initStack(St);
	push(St, 10);
	push(St, 20);
	push(St, 30);
	push(St, 40);
	push(St, 50);
	while (!empty(St)) {
		cout << top(St) << " " << "栈空间的大小为：" << size(St);
		pop(St);
	}
	return 0;
}