#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void menu() {
	cout << "------------------------------------" << endl;
	cout << "---------  1. ���ѧ����Ϣ ---------" << endl;
	cout << "---------  2. ɾ��ѧ����Ϣ ---------" << endl;
	cout << "---------  3. ��ӡѧ����Ϣ ---------" << endl;
	cout << "---------  4. ����ѧ����Ϣ ---------" << endl;
	cout << "---------  0. �˳�         ---------" << endl;
	cout << "------------------------------------" << endl;
}

int main()
{
	list* head = init_list();
	int n = 0;
	student stu("", "", "");
	string id, name, mark;
	do {
		system("cls");
		menu();
		cout << "���������ѡ��" << endl;
		cin >> n;
		int count = 0;
		switch (n) {
		case EXIT:
			save_stu(head);
			cout << "�����˳�" << endl;
			system("pause");
			break;
		case ADD:
		{
			cout << "��������Ҫ��Ӽ���ѧ����Ϣ��" << endl;
			cin >> count;
			for (int i = 0; i < count; i++) {
				cout << "�������" << i + 1 << "��ѧ����ѧ�ţ�"; cin >> id;
				cout << "�������" << i + 1 << "��ѧ����������"; cin >> name;
				cout << "�������" << i + 1 << "��ѧ���ĳɼ���"; cin >> mark;
				stu.id = id; stu.mark = mark; stu.name = name;
				add_stu(head, stu);
				cout << "��ӳɹ���" << endl;
			}
			system("pause");
			break;
		}
		case DEL:
		{
			bool flag = false;
			print_list(head);
			cout << "��������Ҫɾ����ѧ��ѧ�ţ�";
			cin >> id;
			int count = count_stu(head, id);
			while (count--) {
				del_stu(head, id);
				flag = true;
			}
			if(flag)
				cout << "ɾ���ɹ���" << endl;
			else
				cout << "��id�����ڣ�" << endl;
			system("pause");
			break;
		}
		case PRINT:
			print_list(head);
			system("pause");
			break;
		case SAVE:
			save_stu(head);
			system("pause");
			break;
		}
	} while (n);
	return 0;
}