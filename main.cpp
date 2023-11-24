#include <iostream>
#include "./header/var.h"

using namespace std;

int main()
{
    int n;
    bool flag = true;
    do
    {
        cout << "which one : \n";
        cout << "1)Add\n";
        cout << "2)Search\n";
        cout << "3)Delete\n";
        cout << "4)Delete_all\n";
        cout << "5)Show\n";
        cout << "6)Sort\n";
        cout << "7)Import\n";
        cout << "8)Save\n";
        cout << "9)Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            // Add();
            break;
        case 2:
            // Search();
            break;
        case 3:
            // Delete();
            break;
        case 4:
            // Delete_all();
            break;
        case 5:
            // Show();
            break;
        case 6:
            // Sort();
            break;
        case 7:
            // Import();
            break;
        case 8:
            // Save();
            break;
        case 9:
            // Exit();
            flag = false;
            break;
        }

    } while (flag);
}
