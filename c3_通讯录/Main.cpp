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
	cout << "����Ŀ¼��" << endl
		<< "1 �������ϵ��"<<endl<< "2 ����ʾ��ϵ��"<< endl << "3 ��ɾ����ϵ��"<<endl<< "4 ��������ϵ��" << endl << "5 ���޸���ϵ��"<<endl<< "6 �������ϵ��" << endl << "7 ���˳�ͨѶ¼" << endl;
	while (num != 1001) {
		cout << "�����������蹦�ܵı�ţ�";
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
			cout << "��ӭ�´ι���" << endl;
			return 0;
			break;
		default:
			cout << "����������������룡";
			break;
		}
		
	}
	return 0;
}

void addperson(Person* p, int *num) {
	cout << "������������ϵ�˵� ���� �Ա� ���� �绰 ��ͥסַ��" << endl;
	cin >> p->name >> p->gendar >> p->age >> p->phone >> p->adress;
	cout << "------------------��ȴ������ڴ���------------------" << endl;
	*num = *num + 1;
	cout << "��ӳɹ���"<<endl;
}

void showperson(Person* p, int *num) {
	cout << "����" << *num << "����ϵ��" << endl;
	cout << "����\t" << "�Ա�\t" << "����\t" << "�绰\t" << "סַ\t" << endl;
	for (int j = 0; j < *num; j++) {
		cout << (p - *num + j + 1)->name<<"\t" << (p - *num + j + 1)->gendar<<"\t" << (p - *num + j + 1)->age<<"\t" << (p - *num + j + 1)->phone <<"\t" << (p - *num + j + 1)->adress << endl;
	}
	cout << "--------------------��ʾ���--------------------" << endl;
}
void deleteperson(Person* p, int *num) {
	cout << "��������Ҫɾ������ϵ��������";
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
			cout<< "--------------------ɾ�����--------------------" << endl;
			*num = *num - 1;
			break;
		}
	}
	
}

void searchperson(Person* p, int *num) {
	cout << "��������Ҫ���ҵ���ϵ��������";
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
			cout << "����\t" << "�Ա�\t" << "����\t" << "�绰\t" << "סַ\t" << endl;
			cout << (p - *num + i +1)->name << "\t" << (p - *num + i+1)->gendar << "\t" << (p - *num + i+1)->age << "\t" << (p - *num + i+1)->phone << "\t" << (p - *num + i+1)->adress << endl;
			break;
		}
	}
	if (check != 1) {
		cout << "���޴��ˣ�" << endl;
	}
}

void changeperson(Person* p, int* num) {
	cout << "��������Ҫ�޸ĵ���ϵ��������";
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
			cout << "���������ϵ���޸ĺ�ĸ�����Ϣ��" << endl;
			cout << "����\t" << "�Ա�\t" << "����\t" << "�绰\t" << "סַ\t" << endl;
			cin >> (p - *num + i + 1)->name >> (p - *num + i + 1)->gendar >> (p - *num + i + 1)->age >> (p - *num + i + 1)->phone >> (p - *num + i + 1)->adress;
			cout<< "--------------------�޸����--------------------" << endl;
			break;
		}
	}
	if (check != 1) {
		cout << "���޴��ˣ�" << endl;
	}
}

void clearperson(Person* p, int *num) {
	cout << "--------------------�������--------------------" << endl;
	for (int i = 0; i < *num; i++) {
		*(p - *num + 1 + i) = *(p - *num + 1 + 1000);
	}
	*num = 0;
	cout<< "--------------------������--------------------" << endl;
}

void goout(int *num) {
	*num = 1001;
	cout << "���ݰ������ϣ���" << endl;
}
