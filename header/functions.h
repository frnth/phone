#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "var.h"
#include <vector>
#include "./json.hpp"
#include <fstream>


using namespace std;

string Cast_Int_TO_PhoneType(int n)
{
    switch (n)
    {
    case 0:
        return "Fax";
    case 1:
        return "Office";
    case 2:
        return "Work";
    case 3:
        return "Home";
    case 4:
        return "Main";
    default:
        return "Unknown";
    }
}


void Add()
{
    user user;
    cout << "enter new contact name : ";
    cin >> user.name;
    cout << "enter new contact lastname : ";
    cin >> user.family;
    cout << "enter new contact email : ";
    cin >> user.email;
    bool flag = true;

    do
    {
        number h_user;
        cout << "what type of numbers you want to input?(atleast one num) :";
        cout << "choose : \n";
        cout << "1)Fax\n";
        cout << "2)Office\n";
        cout << "3)Work\n";
        cout << "4)Home\n";
        cout << "5)Main\n";
        int n;
        cin >> n;
        h_user.type = phone_type(n - 1);

        cout << "enter number : ";
        cin >> h_user.num;
        user.numbers.push_back(h_user);
        cout << "do you want to enter another number ? (y/n)";
        char c;
        cin >> c;
        if (c == 'y')
        {
            continue;
        }
        else
        {
            flag = false;
        }

    } while (flag);
    phone_book.push_back(user);
}

void Search()
{
    remove_index.clear();
    cout << "enter : ";
    string search_word;
    cin >> search_word;
    int m = -1, c = 1;
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (phone_book[i].name == search_word || phone_book[i].family == search_word)
        {
            cout << c << ") ";
            cout << phone_book[i].name<<"  ";
            cout << phone_book[i].family<<"  ";
            for (const auto &j : phone_book[i].numbers)
            {
                cout << "type : " << Cast_Int_TO_PhoneType(j.type) << " , "
                     << "number : " << j.num << endl;
            }
            remove_index.push_back(i);
            c++;
            m = 1;
        }
        else
        {
            for (const auto &j : phone_book[i].numbers)
            {
                if (j.num == search_word)
                {
                    cout << c << ") ";
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for (const auto &j : phone_book[i].numbers)
                    {
                        cout << "type : " << Cast_Int_TO_PhoneType(j.type) << " , "
                             << "number : " << j.num << endl;
                    }
                    remove_index.push_back(i);
                    c++;
                    m = 1;
                }
            }
        }
    }
    if (m == -1)
    {
        cout << "peyda nashod (?)!!\n";
    }
}

void Delete()
{
    Search();
    cout << "which one ? :";
    int x;
    cin >> x;
    phone_book.erase(phone_book.begin() + remove_index[x]);
}

void Delete_all()
{
    cout << "are you sure?";
    string s;
    cin >> s;
    if (s == "yes")
    {
        phone_book.clear();
    }
}

void Show()
{
    cout << "PHONE BOOK :\n";
    for (int i = 0; i < phone_book.size(); i++)
    {
        cout << "name : " << phone_book[i].name << "  ";
        cout << "family :" << phone_book[i].family << endl;
        cout << "email : " << phone_book[i].email << endl;
        for (const auto &j : phone_book[i].numbers)
        {
            cout << "number : " << j.num << "   (type : " << Cast_Int_TO_PhoneType(int(j.type)) << ")\n";
        }
        cout << "......................\n";
    }
}

void Sort()
{
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book.size() - i - 1; j++)
        {
            if (phone_book[j].name +  phone_book[j].family > phone_book[j + 1].name + phone_book[j + 1].family)
            {
                swap(phone_book[j], phone_book[j + 1]);
            }
        }
    }
}

void Save()
{
    nlohmann::json jsonPhoneBook;

    for (const auto &contact : phone_book)
    {
        nlohmann::json jsonContact;
        jsonContact["name"] = contact.name;
        jsonContact["family"] = contact.family;
        jsonContact["email"] = contact.email;

        nlohmann::json jsonNumbers;
        for (const auto &number : contact.numbers)
        {
            nlohmann::json jsonNumber;
            jsonNumber["num"] = number.num;
            jsonNumber["type"] = static_cast<int>(number.type);
            jsonNumbers.push_back(jsonNumber);
        }

        jsonContact["numbers"] = jsonNumbers;
        jsonPhoneBook.push_back(jsonContact);
    }

    ofstream outputFile("./database/phone_book.json");

    if (!outputFile.is_open())
    {
        cout << "Error creating or opening file for save.\n";
        return;
    }

    outputFile << jsonPhoneBook.dump(4); 
    outputFile.close(); 
    cout << "Save successful.\n";
}

void Import()
{
    ifstream inputFile("./database/phone_book.json");

    if (!inputFile.is_open())
    {
        cout << "Error opening file for import.\n";
        return;
    }

    nlohmann::json jsonPhoneBook;
    inputFile >> jsonPhoneBook;

    phone_book.clear();

    for (const auto &jsonContact : jsonPhoneBook)
    {
        user contact;
        contact.name = jsonContact["name"];
        contact.family = jsonContact["family"];
        contact.email = jsonContact["email"];

        for (const auto &jsonNumber : jsonContact["numbers"])
        {
            number num;
            num.num = jsonNumber["num"];
            num.type = static_cast<phone_type>(jsonNumber["type"]);
            contact.numbers.push_back(num);
        }

        phone_book.push_back(contact);
    }

    cout << "Import successful.\n";
}
#endif // FUNCTIONS_H