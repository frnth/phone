#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "var.h"
#include <vector>
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
    ofstream telephone("telephone.bin", ios::binary | ios::trunc);
    if(telephone) {
        for(int i = 0; i < phone_book.size(); i++) {
            int namelength = phone_book.at(i).name.length();
            telephone.write((char*) &namelength, sizeof(int));
            telephone.write(phone_book.at(i).name.c_str(), namelength);

            int familylength = phone_book.at(i).family.length();
            telephone.write((char*) &familylength, sizeof(int));
            telephone.write(phone_book.at(i).family.c_str(), familylength);

            int emaillength = phone_book.at(i).email.length();
            telephone.write((char*) &emaillength, sizeof(int));
            telephone.write(phone_book.at(i).email.c_str(), emaillength);

            int phonesize = phone_book.at(i).numbers.size();
            telephone.write((char*) &phonesize, sizeof(int));
            for(int j = 0; j < phonesize; j++) {
                string ss = Cast_Int_TO_PhoneType(phone_book.at(i).numbers.at(j).type);
                int phonelength1 = ss.length();
                telephone.write((char*) &phonelength1, sizeof(int));
                telephone.write(ss.c_str(), phonelength1);

                int phonelength2 = phone_book.at(i).numbers.at(j).num.length();
                telephone.write((char*) &phonelength2, sizeof(int));
                telephone.write(phone_book.at(i).numbers.at(j).num.c_str(), phonelength2);
            }
            

        }
        telephone.close();
    }
   
}

void Import()
{
    ifstream add_file = ("phonefile.bin", ios::binary);
    int i = 0;
    if(add_file) {
        while(add_file) {
            add_file.resize(i + 1);
            int nameLength;
            add_file.read((char*)&nameLength, sizeof(int)); 
            phone_book.at(i).name.resize(nameLength); 
            add_file.read(&phone_book.at(i).name[0], nameLength);
            
            int familyLength;
            add_file.read((char*)&familyLength, sizeof(int)); // خواندن طول فامیل از فایل
            phone_book.at(i).family.resize(familyLength); // تغییر اندازه فامیل برابر با طول فامیل
            add_file.read(&phone_book.at(i).family[0], familyLength); // خواندن فامیل از فایل


            int emailLength;
            fin.read((char*)&emailLength, sizeof(int)); // خواندن طول ایمیل از فایل
            saveContact.at(i).email.resize(emailLength); // تغییر اندازه ایمیل برابر با طول ایمیل
            fin.read(&saveContact.at(i).email[0], emailLength); // خواندن ایمیل از فا

            int phoneSize;
            fin.read((char*)&phoneSize, sizeof(int)); // خواندن تعداد شماره های تلفن از فایل
            saveContact.at(i).phoneNumber.resize(phoneSize); // تغییر اندازه بردار شماره های تلفن برابر با تعداد شماره های تلفن
            for (int j = 0; j < phoneSize; j++)
            {
                int phoneLength;
                fin.read((char*)&phoneLength, sizeof(int)); // خواندن طول هر شماره تلفن از فایل
                saveContact.at(i).phoneNumber.at(j).resize(phoneLength); // تغییر اندازه هر شماره تلفن برابر با طول شماره تلفن
                fin.read(&saveContact.at(i).phoneNumber.at(j)[0], phoneLength); // خواندن هر شماره تلفن از فایل

                ++;
            }
saveContact.pop_back(); // حذف آخرین عنصر بردار که خالی است
fin.close(); // بستن فای
        }
    }

    
}
#endif // FUNCTIONS_H







saveContact.resize(i + 1);
            // خواندن نام از فایل
            int nameLength;
            fin.read((char*)&nameLength, sizeof(int)); // خواندن طول نام از فایل
            saveContact.at(i).name.resize(nameLength); // تغییر اندازه نام برابر با طول نام
            fin.read(&saveContact.at(i).name[0], nameLength); // خواندن نام از فایل

            // خواندن فا int familyLength;
fin.read((char*)&familyLength, sizeof(int)); // خواندن طول فامیل از فایل
saveContact.at(i).family.resize(familyLength); // تغییر اندازه فامیل برابر با طول فامیل
fin.read(&saveContact.at(i).family[0], familyLength); // خواندن فامیل از فایل

int emailLength;
fin.read((char*)&emailLength, sizeof(int)); // خواندن طول ایمیل از فایل
saveContact.at(i).email.resize(emailLength); // تغییر اندازه ایمیل برابر با طول ایمیل
fin.read(&saveContact.at(i).email[0], emailLength); // خواندن ایمیل از فایل

            // خواندن شماره های تلفن از فایل
int phoneSize;
fin.read((char*)&phoneSize, sizeof(int)); // خواندن تعداد شماره های تلفن از فایل
saveContact.at(i).phoneNumber.resize(phoneSize); // تغییر اندازه بردار شماره های تلفن برابر با تعداد شماره های تلفن
for (int j = 0; j < phoneSize; j++)
{
     int phoneLength;
 fin.read((char*)&phoneLength, sizeof(int)); // خواندن طول هر شماره تلفن از فایل
 saveContact.at(i).phoneNumber.at(j).resize(phoneLength); // تغییر اندازه هر شماره تلفن برابر با طول شماره تلفن
 fin.read(&saveContact.at(i).phoneNumber.at(j)[0], phoneLength); // خواندن هر شماره تلفن از فایل

i++;
}
saveContact.pop_back(); // حذف آخرین عنصر بردار که خالی است
fin.close(); // بستن فایل
    }
    return sa