#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	Heap heap;
	heap_init(&heap);
	int arr[] = { 1,2,9,1,5,7,5,11,23,55,6,4,8 };
	for(int i = 0; i < 13; i++)
		push(&heap, arr[i]);
	while (!heap_empty(&heap)) {
		cout << top(&heap) << " ";
		pop(&heap);
	}
	return 0;
}