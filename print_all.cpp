#include "print_all.hpp"
#include "singleton.hpp"
#include "iostream"

using namespace std;

print_all::print_all()
{
    if (if_access_granted())
    {
        singleton &stored_data = singleton::get_instance();
        for (auto account : stored_data.accounts)
        {
            cout << "Account number: " << account.number << ", amount: " << account.balance << ", status: ";
            if (account.if_open)
            {
                cout << "open." << endl;
            }
            else
            {
                cout << "closed." << endl;
            }
        }
    }
}

print_all::~print_all()
{
}
