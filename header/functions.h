
#include <iostream>
#include "var.h"
#include <vector>

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
    remove_index.clear();
    // vector<int> remove_index;
    cout << "enter : ";
    string search_word;
    cin >> search_word;
    int m = -1, c = 1;
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (phone_book[i].name == search_word || phone_book[i].family == search_word)
        {
            cout << c << ") ";
            cout << phone_book[i].name;
            cout << phone_book[i].family;
            for (const auto &j : phone_book[i].numbers)
            {
                cout << "type : " << phone_type(j.type) << " , "
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
                        cout << "type : " << phone_type(j.type) << " , "
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
        cout << "isgamono gerefti ?!!\n";
    }
}

void Delete()
{
    search();
    cout << "which one ? :";
    int x;
    cin >> x;
    phone_book[remove_index[x]].erase();
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
        cout << phone_book[i].name;
        cout << phone_book[i].family;
        for (const auto &j : phone_book[i].numbers)
        {
            cout << "type : " << phone_type(j.type) << " , "
                 << "number : " << j.num << endl;
        }
    }
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
