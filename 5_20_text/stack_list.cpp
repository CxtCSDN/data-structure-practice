#define _CRT_SECURE_NO_WARNINGS 1

#include"stack_list.h"

void initStack(Stack& St)
{
	St.count = 0;
	St.head = St.tail = new StackNode;
}
int top(Stack& St)
{
	if (St.count == 0)
	{
		cout << "栈中无数据" << endl;
		return 0;
	}
	else
		return St.head->next->val;
}
StackNode* buyNewNode(SDataType val)
{
	StackNode* newnode = new StackNode;
	newnode->next = nullptr;
	newnode->val = val;
	return newnode;
}
void push(Stack& St, SDataType val)
{
	StackNode* newnode = buyNewNode(val);
	StackNode* next = St.head->next;
	St.head->next = newnode;
	newnode->next = next;
	St.count++;
	cout << "插入" << val << "成功" << endl;
}
void pop(Stack& St)
{
	if (St.count != 0)
	{
		SDataType val = St.head->next->val;
		StackNode* next = St.head->next->next;
		free(St.head->next);
		St.head->next = next;
		cout << "出栈成功，出栈的数据为：" <<  val << endl;
		St.count--;

	}
	else
	{
		cout << "当前栈为空" << endl;
		return;
	}
}
bool empty(Stack St)
{
	return St.count == 0;
}
int size(Stack St)
{
	return St.count;
}