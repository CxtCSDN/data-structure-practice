#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void menu() {
	cout << "------------------------------------" << endl;
	cout << "---------  1. 添加学生信息 ---------" << endl;
	cout << "---------  2. 删除学生信息 ---------" << endl;
	cout << "---------  3. 打印学生信息 ---------" << endl;
	cout << "---------  4. 保存学生信息 ---------" << endl;
	cout << "---------  0. 退出         ---------" << endl;
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
		cout << "请输入你的选项" << endl;
		cin >> n;
		int count = 0;
		switch (n) {
		case EXIT:
			save_stu(head);
			cout << "程序退出" << endl;
			system("pause");
			break;
		case ADD:
		{
			cout << "请输入你要添加几名学生信息：" << endl;
			cin >> count;
			for (int i = 0; i < count; i++) {
				cout << "请输入第" << i + 1 << "名学生的学号："; cin >> id;
				cout << "请输入第" << i + 1 << "名学生的姓名："; cin >> name;
				cout << "请输入第" << i + 1 << "名学生的成绩："; cin >> mark;
				stu.id = id; stu.mark = mark; stu.name = name;
				add_stu(head, stu);
				cout << "添加成功！" << endl;
			}
			system("pause");
			break;
		}
		case DEL:
		{
			bool flag = false;
			print_list(head);
			cout << "请输入你要删除的学生学号：";
			cin >> id;
			int count = count_stu(head, id);
			while (count--) {
				del_stu(head, id);
				flag = true;
			}
			if(flag)
				cout << "删除成功！" << endl;
			else
				cout << "此id不存在！" << endl;
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