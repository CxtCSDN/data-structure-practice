#include "Heap.h"
#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include<algorithm>
void heap_init(Heap* heap)
{
	heap->m_heap = (HeapData*)malloc(sizeof(HeapData) * 4);
	heap->size = 0;
	heap->capacity = 4;
}

void destroy_heap(Heap* heap)
{
	free(heap->m_heap);
	heap->m_heap = nullptr;
	heap->capacity = 0;
	heap->size = 0;
}

void AdjustUp(Heap* heap) {
	int child = heap->size - 1;
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (heap->m_heap[child] > heap->m_heap[parent]) {
			swap(heap->m_heap[child], heap->m_heap[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void push(Heap* heap, HeapData x)
{
	if (heap->size == heap->capacity) {
		HeapData* tmp = (HeapData*)realloc(heap->m_heap, sizeof(HeapData) * heap->capacity * 2);
		if (tmp == nullptr) {
			perror("realloc");
			return;
		}
		else
			heap->m_heap = tmp;
		heap->capacity *= 2;
	}
	heap->m_heap[heap->size] = x;
	heap->size++;
	AdjustUp(heap);
}
void AdjustDown(Heap* heap) {
	int parent = 0;
	int child = parent * 2 + 1;
	while (child < heap->size) {
		if (child + 1 < heap->size && heap->m_heap[child] < heap->m_heap[child + 1]) {
			child += 1;
		}
		if (heap->m_heap[child] > heap->m_heap[parent]) {
			swap(heap->m_heap[child], heap->m_heap[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void pop(Heap* heap)
{
	swap(heap->m_heap[0], heap->m_heap[heap->size - 1]);
	heap->size--;
	AdjustDown(heap);
}

HeapData top(Heap* heap)
{
	if (heap->size == 0) {
		cout << "当前堆中无数据" << endl;
		return -1;
	}
	return heap->m_heap[0];
}

bool heap_empty(Heap* heap)
{
	return heap->size == 0;
}

int heap_size(Heap* heap)
{
	return heap->size;
}
