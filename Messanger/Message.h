#pragma once
#include <iostream>
using namespace std;

struct Message {
	char name[50] = "";      //Ім'я отримувача
	char date[11] = "";      //Дата відправлення
	char text[150] = "";     //Текст повідомлення

	void createMessage() {   //Процедура створення повідомлення
		cout << "-------------------------------------------------------------------" << endl;
		cout << "                           CREATE MESSAGE" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "Recipient's name: "; cin.getline(name, 50);    //Заповнення імені отримувача
		cout << "Date[yyyy.mm.dd]: "; cin.getline(date, 11);    //Заповнення дати відправлення
		date[10] = '\0';                                        //Додавання управляючого нуля
		cout << "Text: "; cin.getline(text, 150);               //Заповнення тексту повідомлення
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void showMessage() {    //Виведення повідомлення
		cout << "-------------------------------------------------------------------" << endl;
		cout << "\tName: " << name << endl;                     //Виведення ім'я
		cout << "\tDate: " << date << endl;                     //Виведення дати
		cout << "\tText: " << text << endl;                     //Виведення тексту повідомлення
		cout << "-------------------------------------------------------------------" << endl << endl;
	}

	void saveToTextFile(FILE* fp)      //Збереження повідомлення до текстового файлу
	{
		fprintf(fp, "\n%s\n%s\n%s", name, date, text);
	}

	void loadFromTextFile(FILE* fp)   //Завантаження повідомлення з текстового файлу
	{
		fscanf_s(fp, "\n");                                    
		fgets(name, 50, fp);                                   //Завантаження імені
		name[strlen(name) - 1] = '\0';                         //Додавання управляючого нуля
		fscanf_s(fp, "\n%s", date, 11);                        //Завантаження дати відправлення
		fscanf_s(fp, "\n%s", text, 150);                       //Завантаження тексту повідомлення
	}
};