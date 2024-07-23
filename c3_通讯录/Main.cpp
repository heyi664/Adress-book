#include <iostream>
using namespace std;


struct Person
{
	char name[20];
	char gendar[5];
	int age;
	char phone[20];
	char adress[30];
};

void addperson(Person* p, int *num);
void showperson(Person* p, int *num);
void deleteperson(Person* p, int *num);
void searchperson(Person* p, int *num);
void changeperson(Person* p, int* num);
void clearperson(Person* p, int* num);
void goout(int *num);

int main()
{
	int option;
	int num = 0;
	Person person[1001];
	cout << "功能目录：" << endl
		<< "1 ：添加联系人"<<endl<< "2 ：显示联系人"<< endl << "3 ：删除联系人"<<endl<< "4 ：查找联系人" << endl << "5 ：修改联系人"<<endl<< "6 ：清空联系人" << endl << "7 ：退出通讯录" << endl;
	while (num != 1001) {
		cout << "请输入你所需功能的编号：";
		cin >> option;
		switch (option)
		{
		case 1:
			addperson(&person[num], &num);
			break;
		case 3:
			deleteperson(&person[num-1], &num);
			break;
		case 2:
			showperson(&person[num-1], &num);
			break;
		case 4:
			searchperson(&person[num-1], &num);
			break;
		case 5:
			changeperson(&person[num-1], &num);
			break;
		case 6:
			clearperson(&person[num-1], &num);
			break;
		case 7:
			//goout(&num);
			cout << "欢迎下次光临" << endl;
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入！";
			break;
		}
		
	}
	return 0;
}

void addperson(Person* p, int *num) {
	cout << "请依次输入联系人的 姓名 性别 年龄 电话 家庭住址：" << endl;
	cin >> p->name >> p->gendar >> p->age >> p->phone >> p->adress;
	cout << "------------------请等待，正在处理------------------" << endl;
	*num = *num + 1;
	cout << "添加成功！"<<endl;
}

void showperson(Person* p, int *num) {
	cout << "共有" << *num << "个联系人" << endl;
	cout << "姓名\t" << "性别\t" << "年龄\t" << "电话\t" << "住址\t" << endl;
	for (int j = 0; j < *num; j++) {
		cout << (p - *num + j + 1)->name<<"\t" << (p - *num + j + 1)->gendar<<"\t" << (p - *num + j + 1)->age<<"\t" << (p - *num + j + 1)->phone <<"\t" << (p - *num + j + 1)->adress << endl;
	}
	cout << "--------------------显示完成--------------------" << endl;
}
void deleteperson(Person* p, int *num) {
	cout << "请输入您要删除的联系人姓名：";
	char name_1[20];
	cin >> name_1;
	for (int i = 0; i < *num; i++) {
		int check = 0;
		for (int j = 0; j < 20; j++) {
			if ((p - *num + 1 + i)->name[j] != name_1[j]) {
				check = 0;
				break;
			}
			else {
				check = 1;
			}
		}
		if (check == 1) {
			for (int m = 0; m < 1000-i-1; m++) {
				*(p - *num + i + m+1) = *(p - *num + i + m + 2);
			}
			cout<< "--------------------删除完成--------------------" << endl;
			*num = *num - 1;
			break;
		}
	}
	
}

void searchperson(Person* p, int *num) {
	cout << "请输入您要查找的联系人姓名：";
	char name_1[20];
	cin >> name_1;
	int check = 0;
	for (int i = 0; i < *num; i++) {
		 check = 0;
		 int j;
		for ( j = 0; j < 20; j++) {
			if ((p-*num+1+i)->name[j] != name_1[j]) {
				check = 0;
				break;
			}
			else {
				check = 1;
			}
		}
		if (check == 1) {
			cout << "姓名\t" << "性别\t" << "年龄\t" << "电话\t" << "住址\t" << endl;
			cout << (p - *num + i +1)->name << "\t" << (p - *num + i+1)->gendar << "\t" << (p - *num + i+1)->age << "\t" << (p - *num + i+1)->phone << "\t" << (p - *num + i+1)->adress << endl;
			break;
		}
	}
	if (check != 1) {
		cout << "查无此人！" << endl;
	}
}

void changeperson(Person* p, int* num) {
	cout << "请输入您要修改的联系人姓名：";
	char name_1[20];
	cin >> name_1;
	int check = 0;
	for (int i = 0; i < *num; i++) {
		check = 0;
		for (int j = 0; j < 20; j++) {
			if ((p - *num + 1 + i)->name[j] != name_1[j]) {
				break;
			}
			else {
				check = 1;
			}
		}
		if (check == 1) {
			cout << "请输入该联系人修改后的各项信息。" << endl;
			cout << "姓名\t" << "性别\t" << "年龄\t" << "电话\t" << "住址\t" << endl;
			cin >> (p - *num + i + 1)->name >> (p - *num + i + 1)->gendar >> (p - *num + i + 1)->age >> (p - *num + i + 1)->phone >> (p - *num + i + 1)->adress;
			cout<< "--------------------修改完成--------------------" << endl;
			break;
		}
	}
	if (check != 1) {
		cout << "查无此人！" << endl;
	}
}

void clearperson(Person* p, int *num) {
	cout << "--------------------正在清空--------------------" << endl;
	for (int i = 0; i < *num; i++) {
		*(p - *num + 1 + i) = *(p - *num + 1 + 1000);
	}
	*num = 0;
	cout<< "--------------------清空完成--------------------" << endl;
}

void goout(int *num) {
	*num = 1001;
	cout << "·拜拜了您嘞！·" << endl;
}
