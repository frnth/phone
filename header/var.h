

#include <string>

using namespace std;
enum phone_type
{
    Fax,
    Office,
    Work,
    Home,
    Main,
};
struct number
{
    string num;
    phone_type type;
};

struct user
{
    string name;
    string family;
    string email;
    vector<number> numbers;
};

vector<user> phone_book;
vector<int> remove_index;