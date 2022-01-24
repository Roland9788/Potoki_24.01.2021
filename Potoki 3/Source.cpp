#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;



void RussianMassage(const char* massage)
{
	char remessage[256];
	CharToOemA(massage, remessage);
	cout << remessage;
}
int RussianMenu()
{
	RussianMassage("\n������� 1 ��� ���������� ����� ��������� � ����\n");
	RussianMassage("\n������� 2 ��� ������ ���� �������� �� �����\n");
	RussianMassage("\n������� 3 ��� ������\n");
	int choice;
	cin >> choice;
	return choice;
}

class Man
{
	int age;
	char* name;
	char* surname;
public:
	Man(const char* n, const char* s, int a)
	{
		name = new char[strlen(n) + 1];
		if (!name)
			RussianMassage("������ ��� ��������� ������ !!!");
		exit(1);
		strcpy(name, n);
		surname = new char[strlen(s) + 1];
		if (!surname)
			RussianMassage("������ ��� ��������� ������ !!!");
		exit(1);
		strcpy(surname, s);
		age = a;
	}

	Man()
	{
		name = 0;
		surname = 0;
		age = 0;
	}
	~Man()
	{
		delete[] name;
		delete[] surname;
	}
	void Put()
	{
		char temp[1024];
		RussianMassage("\n������� ���:\n");
		cin >> temp;
		if (name)
			delete[]name;
		name = new char[strlen(temp) + 1];
		if (!name)
		{
			RussianMassage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(name, temp);

		RussianMassage("\n������� �������:\n");
		cin >> temp;
		if (surname)
			delete[]surname;
		surname = new char[strlen(temp) + 1];
		if (!surname)
		{
			RussianMassage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(surname, temp);

		RussianMassage("\n������� �������:\n");
		cin >> age;

	}

	void Show()
	{
		RussianMassage("\n���:\n");
		cout << name;
		RussianMassage("\n�������:\n");
		cout << surname;
		RussianMassage("\n�������:\n");
		cout << age << endl;
	}

	void SaveToFile()
	{
		ofstream f("D:\\Men.txt", ios::out | ios::binary | ios::app);
		if (!f)
		{
			RussianMassage("\n���� �� �������� ��� ������!!!:\n");
			exit(1);
		}
		f << name;
		f << "\n";
		f << surname;
		f << "\n";
		f << age;
		f.close();
	}

	void ShowFromFile()
	{
		ifstream f("D:\\Men.txt", ios::out | ios::binary);
		if (!f)
		{
			RussianMassage("���� �� �������� ��� ������!!!");
			exit(1);
		}

		while (f.good())
		{
			char buff[50];
			int a;
			f >> buff;
			RussianMassage("\n���:\n");
			cout << buff;
			f >> buff;
			RussianMassage("\n�������:\n");
			cout << buff;
			RussianMassage("\n�������:\n");
			f >> a;
			cout << a << endl;
		}


	}
};

int main()
{
	//setlocale(LC_ALL, "Rus");
	Man* a;
	a = new Man;
	do
	{
		switch (RussianMenu())
		{
		case 1:
			a->Put();
			a->SaveToFile();
			break;
		case 2:
			a->ShowFromFile();
			break;
		case 3:
			RussianMassage("\n�� ��������\n");
			return 0;
		default:
			RussianMassage("\n�������� ����\n");
		}
	} while (1);
	return 0;
}