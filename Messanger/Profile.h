#pragma once
#include <iostream>
using namespace std;

struct Profile {
	//Поля структури
	char name[100] = "";   //Ім'я контакту
	char mail[50] = "";    //Поштова скринька контакту
	char number[14] = "";  //Номер телефону контакту

	void fillProfile() //Процедура заповнення профілю
	{
		cout << "-------------------------------------------------------------------" << endl;
		cout << "                            FILL INFO" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Name: "; cin.getline(name, 100);             //Заповнення ім'я
		cout << "Mail: "; cin.getline(mail, 50);              //Заповнення пошти
		cout << "Phone number: "; cin.getline(number, 14);    //Заповнення номер телефону
		number[13] = '\0';
		cout << "-------------------------------------------------------------------" << endl << endl;
	}
	void showProfile() { //Процедура виведення профілю в консоль
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Name: " << name << endl;                     //Виведення ім'я
		cout << "Mail: " << mail << endl;                     //Виведення пошти
		cout << "Phone number: " << number << endl;           //Виведення номеру телефону
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void saveToTextFile(FILE* fp) //Процедура зберігання профілю у текстовий файл
	{
		fprintf(fp, "\n%s\n%s\n%s", name, mail, number);      
	}

	void loadFromTextFile(FILE* fp) //Процедура завантаження профілю з текстового файлу
	{
		fscanf_s(fp, "\n");
		fgets(name, 50, fp);                                  //Завантаження імені
		name[strlen(name) - 1] = '\0';                        //Введення управляючого нуля
		fscanf_s(fp, "\n%s", mail, 50);                       //Завантаження пошти
		fscanf_s(fp, "\n%s", number, 14);                     //Завантаження номеру
	}
};