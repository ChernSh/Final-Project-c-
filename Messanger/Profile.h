#pragma once
#include <iostream>
using namespace std;

struct Profile {
	//���� ���������
	char name[100] = "";   //��'� ��������
	char mail[50] = "";    //������� �������� ��������
	char number[14] = "";  //����� �������� ��������

	void fillProfile() //��������� ���������� �������
	{
		cout << "-------------------------------------------------------------------" << endl;
		cout << "                            FILL INFO" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Name: "; cin.getline(name, 100);             //���������� ��'�
		cout << "Mail: "; cin.getline(mail, 50);              //���������� �����
		cout << "Phone number: "; cin.getline(number, 14);    //���������� ����� ��������
		number[13] = '\0';
		cout << "-------------------------------------------------------------------" << endl << endl;
	}
	void showProfile() { //��������� ��������� ������� � �������
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Name: " << name << endl;                     //��������� ��'�
		cout << "Mail: " << mail << endl;                     //��������� �����
		cout << "Phone number: " << number << endl;           //��������� ������ ��������
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void saveToTextFile(FILE* fp) //��������� ��������� ������� � ��������� ����
	{
		fprintf(fp, "\n%s\n%s\n%s", name, mail, number);      
	}

	void loadFromTextFile(FILE* fp) //��������� ������������ ������� � ���������� �����
	{
		fscanf_s(fp, "\n");
		fgets(name, 50, fp);                                  //������������ ����
		name[strlen(name) - 1] = '\0';                        //�������� ������������ ����
		fscanf_s(fp, "\n%s", mail, 50);                       //������������ �����
		fscanf_s(fp, "\n%s", number, 14);                     //������������ ������
	}
};