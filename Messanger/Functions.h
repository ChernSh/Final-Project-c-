#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Profile.h"
#include "Message.h"
using namespace std;

void printList(Profile arr[], int size) {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "                           CONTACT LIST" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << endl;
		arr[i].showProfile();
	}
	cout << endl;
}

void printList(Message arr[], int size) {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "                           MESSAGE LIST" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << endl;
		arr[i].showMessage();
	}
	cout << endl;
}

void listSort(Profile arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	printList(arr, size);
}

void listSort(Message arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].date, arr[j + 1].date) > 0) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	printList(arr, size);
}

void deleteContact(Profile*& arr, int& size, int index)
{
		for (int j = index; j < size - 1; j++) {
				swap(arr[j], arr[j + 1]);
		}
	size--;
}

void findContact(Profile arr[], int &size)
{
	int option1 = -1, option2 = -1, index = 0;
	char input[50] = "";
	cout << "-------------------------------------------------------------------" << endl;
	cout << "                           FIND CONTACT" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "    0. Return" << endl;
	cout << "    1. Find by name" << endl;
	cout << "    2. Find by mail" << endl;
	cout << "    3. Find by number" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Selected option: "; cin >> option1;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "                          CONTACT INFO" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cin.ignore();
		switch (option1)
		{
		default:
			break;
		case 1:
			cout << "Name: "; cin.getline(input, 50);
			for (int i = 0; i < size; i++)
			{
				if (strcmp(arr[i].name, input) == 0)
				{
					arr[i].showProfile();
					index = i;
				}
			}
			break;
		case 2:
			cout << "Mail: "; cin.getline(input, 50);
			for (int i = 0; i < size; i++)
			{
				if (strcmp(arr[i].mail, input) == 0)
				{
					arr[i].showProfile();
					index = i;
				}
			}
			break;
		case 3:
			cout << "Phone number: "; cin.getline(input, 50);
			for (int i = 0; i < size; i++)
			{
				if (strcmp(arr[i].number, input) == 0)
				{
					arr[i].showProfile();
					index = i;
				}
			}
		}
		if (index < 0 || index >= size) cout << endl << "Contact not found" << endl;
		else {
			cout << "-------------------------------------------------------------------" << endl;
			cout << "    0. Return" << endl;
			cout << "    1. Edit" << endl;
			cout << "    2. Delete" << endl;
			cout << "-------------------------------------------------------------------" << endl;
			cout << "Selected option: "; cin >> option2;
			cout << "-------------------------------------------------------------------" << endl;
			if (option2 == 1)
			{
				arr[index].fillProfile();
			}
			else if (option2 == 2)
			{
				deleteContact(arr, size, index);
			}
		}
}

void addItem(Profile*& arr, int& size)
{
	Profile* tmp = new Profile[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	Profile item = { '\0' };
	item.fillProfile();
	tmp[size] = item;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
	size++;
}

void addItem(Message*& arr, int& size)
{
	Message* tmp = new Message[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	Message item = { '\0' };
	item.createMessage();
	tmp[size] = item;
	if (arr != nullptr) delete[] arr;
	arr = tmp;
	size++;
}

