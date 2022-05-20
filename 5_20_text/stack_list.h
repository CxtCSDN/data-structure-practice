#pragma once

#pragma once

#include<cstdlib>
#include<iostream>

using namespace std;

typedef int SDataType;

typedef struct StackNode {
	SDataType val;
	struct StackNode* next;
}StackNode;

typedef struct Stack
{
	int count;
	StackNode* tail;
	StackNode* head;
}Stack;

void initStack(Stack& St);
int top(Stack& St);

void push(Stack& St, SDataType val);
void pop(Stack& St);
bool empty(Stack St);
int size(Stack St);
