#pragma once

#include<iostream>

using namespace std;

typedef int HeapData;

typedef struct Heap {
	HeapData* m_heap;
	int size;
	int capacity;
}Heap;


void heap_init(Heap* heap);

void destroy_heap(Heap* heap);

void push(Heap* heap, HeapData x);

void pop(Heap* heap);

HeapData top(Heap* heap);

bool heap_empty(Heap* heap);

int heap_size(Heap* heap);

