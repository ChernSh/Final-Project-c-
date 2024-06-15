#include <iostream>
#include "Profile.h"
#include "Message.h"
#include "Functions.h"
using namespace std;

int main()
{
    FILE* contactsFile = nullptr;
    FILE* messageFile = nullptr;
    fopen_s(&contactsFile, "contacts.txt", "r");
    fopen_s(&messageFile, "messages.txt", "r");
    Profile user = { '\0' };
    cout << endl << "\t\tWelcome! Please, fill your profile." << endl;
    user.fillProfile();
    cout << "\tHello, " << user.name << "! Let's start session." << endl << endl;
    int option1 = -1;
    Message* messages;
    Profile* contacts;
    int sizeM = 0, sizeP = 1;
    if (contactsFile == nullptr) {
        cout << "\tYou don't have any contacts yet. Let's add the first one." << endl << endl;
        contacts = new Profile[sizeP];
        contacts[0].fillProfile();
        messages = nullptr;
    }
    else {
        fscanf_s(contactsFile, "%d", &sizeP);
        contacts = new Profile[sizeP];
        for (int i = 0; i < sizeP; i++)
        {
            contacts[i].loadFromTextFile(contactsFile);
        }
        fclose(contactsFile);
        if (messageFile != nullptr)
        {
            fscanf_s(messageFile, "%d", &sizeM);
            messages = new Message[sizeM];
            for (int i = 0; i < sizeM; i++)
            {
                messages[i].loadFromTextFile(messageFile);
            }
            fclose(messageFile);
        }
        else messages = new Message[50];
    }

    while (option1 != 0)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "                             MENU" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "    0. Exit" << endl;
        cout << "    1. View the message list" << endl;
        cout << "    2. View the contact list" << endl;
        cout << "    3. Edit your profile" << endl;
        cout << "    4. Add contact" << endl;
        cout << "    5. Find contact" << endl;
        cout << "    6. Send message" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Selected option: "; cin >> option1;
        switch (option1)
        {
        default:
            break;
        case 1:
            if (messages != nullptr)
            {
                int option2 = -1;
                printList(messages, sizeM);
                cout << "-------------------------------------------------------------------" << endl;
                cout << "    0. Return" << endl;
                cout << "    1. Sort" << endl;
                cout << "-------------------------------------------------------------------" << endl;
                cout << "Selected option: "; cin >> option2;
                cout << "-------------------------------------------------------------------" << endl;
                if (option2 == 1) listSort(messages, sizeM);
            }
            else cout << "\t\tYou don't have any messages yet." << endl;
            break;
        case 2:
            if (contacts != nullptr)
            {
                int option2 = -1;
                printList(contacts, sizeP);
                cout << "-------------------------------------------------------------------" << endl;
                cout << "    0. Return" << endl;
                cout << "    1. Sort" << endl;
                cout << "-------------------------------------------------------------------" << endl;
                cout << "Selected option: "; cin >> option2;
                cout << "-------------------------------------------------------------------" << endl;
                if (option2 == 1) listSort(contacts, sizeP);
            }
            else cout << "You don't have any contacts yet." << endl;
            break;
        case 3:
            cin.ignore();
            user.fillProfile(); break;
        case 4:
            cin.ignore();
            addItem(contacts, sizeP); break;
        case 5:
            cin.ignore();
            findContact(contacts, sizeP);
            break;
        case 6:
            cin.ignore();
            addItem(messages, sizeM); break;
        }
    }
    fopen_s(&contactsFile, "contacts.txt", "w");
    if (contactsFile != nullptr)
    {
        fprintf(contactsFile, "%d", sizeP);
        for (int i = 0; i < sizeP; i++)
        {
            contacts[i].saveToTextFile(contactsFile);
        }
        fclose(contactsFile);
    }
    fopen_s(&messageFile, "messages.txt", "w");
    if (messageFile != nullptr)
    {
        fprintf(messageFile, "%d", sizeM);
        for (int i = 0; i < sizeM; i++)
        {
            messages[i].saveToTextFile(messageFile);
        }
        fclose(messageFile);
    }
    delete[] contacts; delete[] messages;
}

