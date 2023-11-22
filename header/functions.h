
#include <iostream>
#include <./header/var.h>

using namespace std;

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
        if(c == 'y'){
            continue;
        }else{
            flag = false;
        }

    } while (flag);
    phone_book.push_back(user);
}

void Search()
{
    cout << "based on what factor you are looking for the person you want? \n";
    cout << "1)name\n";
    cout << "2)lastname\n";
    cout << "3)phone numbers\n";
    int x;
    cin >> x;
    while (x < 0 || x > 3)
    {
        cout << "ERROR!\n";
        cin >> x;
    }
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
