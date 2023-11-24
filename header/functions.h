
#include <iostream>
#include "var.h"

using namespace std;

string phone_type(int n)
{
    switch (n)
    {
    case 0:
        return "Fax";
        break;
    case 1:
        return "Office";
        break;
    case 2:
        return "Work";
        break;
    case 3:
        return "Home";
        break;
    case 4:
        return "Main";
        break;
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
        h_user.type = phone_type(n);

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
    cout << "enter : ";
    string search_word;
    cin >> search_word;
    int m = -1;
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (phone_book[i].name == search_word || phone_book[i].family == search_word)
        {
            cout << phone_book[i].name;
            cout << phone_book[i].family;
            for (auto j : phone_book[i].numbers)
            {
                cout << "type : " << phone_type(j.type) << " , " 
                << "number : " << j.num << endl;
            }
            m = 1;
        }
        else
        {
            for (auto j : phone_book[i].numbers)
            {
                if (j.num == search_word)
                {
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for (auto j : phone_book[i].numbers)
                    {
                        cout << "type : " << phone_type(j.type) << " , " 
                        << "number : " << j.num << endl;
                    }
                    m = 1;
                }
            }
        }

    }
    if(m == -1){
        cout << "isgamono gerefti ?!!\n";
    }
   
    /*
    cout << "if you don't have any of the following information, write none. \n";
    cout << "please enter the name: ";
    string name;
    cin >> name;
    cout << "please enter the lastname: ";
    string lastname;
    cin >> lastname;
    cout << "please enter the number: ";
    string n;
    cin >> n;
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (name != "none" && phone_book[i].name == name)
        {
            if (lastname != "none" && phone_book[i].family == lastname)
            {
                int m = 1;
                if (n != "none")
                {
                    for (auto j : phone_book[i].numbers)
                    {
                        if (j.num == n)
                        {
                            cout << "name : " << phone_book[i].name << endl;
                            cout << "lastname : " << phone_book[i].family << endl;
                            for(auto j : phone_book[i].numbers) {
                                cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                            }
                            m = -1;
                        }
                    }
                    if (m == 1)
                    {
                        cout << "not found !\n";
                    }
                }
                else
                {
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for(auto j : phone_book[i].numbers) {
                        cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                    }
                }
            }
            else
            {
                int m = 1;
                if (n != "none")
                {
                    for (auto j : phone_book[i].numbers)
                    {
                        if (j.num == n)
                        {
                            cout << "name : " << phone_book[i].name << endl;
                            cout << "lastname : " << phone_book[i].family << endl;
                            for(auto j : phone_book[i].numbers) {
                                cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                            }
                            m = -1;
                        }
                    }
                    if (m == 1)
                    {
                        cout << "not found !\n";
                    }
                }
                else
                {
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for(auto j : phone_book[i].numbers) {
                        cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                    }
                }
            }
        }
        else
        {
            if (lastname != "none" && phone_book[i].family == lastname)
            {
                int m = 1;
                if (n != "none")
                {
                    for (auto j : phone_book[i].numbers)
                    {
                        if (j.num == n)
                        {
                            cout << "name : " << phone_book[i].name << endl;
                            cout << "lastname : " << phone_book[i].family << endl;
                            cout << "number: " << j.num << endl;
                            m = -1;
                        }
                    }
                    if (m == 1)
                    {
                        cout << "not found !\n";
                    }
                }
                else
                {
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for(auto j : phone_book[i].numbers) {
                        cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                    }
                }
            }
            else
            {
                int m = 1;
                if (n != "none")
                {
                    for (auto j : phone_book[i].numbers)
                    {
                        if (j.num == n)
                        {
                            cout << "name : " << phone_book[i].name << endl;
                            cout << "lastname : " << phone_book[i].family << endl;
                            cout << "number: " << j.num << endl;
                            m = -1;
                        }
                    }
                    if (m == 1)
                    {
                        cout << "not found !\n";
                    }
                }
                else
                {
                    cout << "name : " << phone_book[i].name << endl;
                    cout << "lastname : " << phone_book[i].family << endl;
                    for(auto j : phone_book[i].numbers) {
                        cout << "type : " << phone_type(j.type) << " , " << "number : " << j.num << endl;
                    }
                }
            }
            //cout << "isgamono gerefti ?!!\n";
        }
    }*/
}

void Delete()
{
    cout << "what do you know about him or her ?\nenter opthion below: \n";
    cout << "1)name\n";
    cout << "2)lastname\n";
    cout << "3)phone numbers\n";
    int n;
    cin >> n;
}

void Delete_all()
{
}

void Show()
{
}

void Sort()
{
}

void Save()
{
}

void Import()
{
}
