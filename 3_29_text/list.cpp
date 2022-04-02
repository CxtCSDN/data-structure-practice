#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

static list* buy_node(student stu) {
	list* newnode = new list(NULL, NULL, student("", "", ""));
	newnode->stu.id = stu.id;
	newnode->stu.mark = stu.mark;
	newnode->stu.name = stu.name;
	return newnode;
}

list* init_list() {
	list* head = buy_node(student("", "", ""));
	head->next = head;
	head->prev = head;
	load_info(head);
	return head;
}

void load_info(list* head) {
	ifstream ifs;
	ifs.open("stu_info.txt", ios::in);
	string ID;
	string name;
	string mark;
	int Index = 0;
	while (ifs >> ID && ifs >> name && ifs >> mark)
	{
		student stu(ID, name, mark);
		add_stu(head, stu);
	}
	ifs.close();

}

void add_stu(list* head, student stu) {
	list* newnode = buy_node(stu);
	list* tail = head->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = head;
	head->prev = newnode;
}

void print_list(list* head)
{
	list* cur = head->next;
	if (cur == head) {
		cout << "��ǰ��������Ϣ��" << endl;
		return;
	}
	while (cur != head)
	{
		cout << cur->stu.id << " " << cur->stu.name << " " << cur->stu.mark << endl;
		cur = cur->next;
	}
	cout << endl;
}

int count_stu(list* head, string id) {
	int count = 0;
	list* cur = head->next;
	while (cur != head) {
		if(!cur->stu.id.compare(id))
			count++;
		cur = cur->next;
	}
	return count;
}

static list* find_stu(list* head, string id) {
	list* cur = head->next;
	while (cur != head) {
		if (!cur->stu.id.compare(id)) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void del_stu(list* head, string id) {
	list* pos = find_stu(head, id);
	if (pos != NULL) {
		list* prev = pos->prev;
		list* next = pos->next;
		prev->next = next;
		next->prev = prev;
		delete(pos);
		return;
	}
}

void save_stu(list* head) {
	list* cur = head->next;
	if (cur == head) {
		cout << "��ǰ��������Ϣ��" << endl;
		return;
	}
	else {
		FILE* pFile = fopen("stu_info.txt", "w");
		string tmp = "";
		//string����ֱ��ת��const char*������ļ�ʱ�����������������ԱҲ��������ļ�����
		//������һ���ַ�ָ����Ϊ��ת���պ���������ļ��Խ�����������
		const char* _tmp;
		while (cur != head) {
			tmp = (cur->stu.id + " " + cur->stu.name + " " + cur->stu.mark + "\n");
			_tmp = (char*)tmp.c_str();
			fputs(_tmp, pFile);
			cur = cur->next;
		}
		fclose(pFile);
		cout << "����ɹ���" << endl;
	}
}
