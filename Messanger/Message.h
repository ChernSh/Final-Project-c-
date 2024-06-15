#pragma once
#include <iostream>
using namespace std;

struct Message {
	char name[50] = "";      //��'� ����������
	char date[11] = "";      //���� �����������
	char text[150] = "";     //����� �����������

	void createMessage() {   //��������� ��������� �����������
		cout << "-------------------------------------------------------------------" << endl;
		cout << "                           CREATE MESSAGE" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Recipient's name: "; cin.getline(name, 50);    //���������� ���� ����������
		cout << "Date[yyyy.mm.dd]: "; cin.getline(date, 11);    //���������� ���� �����������
		date[10] = '\0';                                        //��������� ������������ ����
		cout << "Text: "; cin.getline(text, 150);               //���������� ������ �����������
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void showMessage() {    //��������� �����������
		cout << "-------------------------------------------------------------------" << endl;
		cout << "\tName: " << name << endl;                     //��������� ��'�
		cout << "\tDate: " << date << endl;                     //��������� ����
		cout << "\tText: " << text << endl;                     //��������� ������ �����������
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void saveToTextFile(FILE* fp)      //���������� ����������� �� ���������� �����
	{
		fprintf(fp, "\n%s\n%s\n%s", name, date, text);
	}

	void loadFromTextFile(FILE* fp)   //������������ ����������� � ���������� �����
	{
		fscanf_s(fp, "\n");                                    
		fgets(name, 50, fp);                                   //������������ ����
		name[strlen(name) - 1] = '\0';                         //��������� ������������ ����
		fscanf_s(fp, "\n%s", date, 11);                        //������������ ���� �����������
		fscanf_s(fp, "\n%s", text, 150);                       //������������ ������ �����������
	}
};