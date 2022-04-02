#pragma once

#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

enum Option {
	EXIT,
	ADD,
	DEL,
	PRINT,
	SAVE,
};

typedef struct Student {
	string id;
	string name;
	string mark;
	Student(string _id, string _name, string _mark) : id(_id), name(_name), mark(_mark) {}
}student;

typedef struct List {
	struct List* prev;
	struct List* next;
	int count;
	student stu;
	List(struct List* pr, struct List* ne, student st) : prev(pr), next(ne), stu(st) {}
}list;

list* init_list();

void load_info(list* head);

void add_stu(list* head, student stu);

void print_list(list* head);

int count_stu(list* head, string id);

void del_stu(list* head, string id);

void save_stu(list* head);