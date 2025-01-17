#include "close_account.hpp"
#include "iostream"

using namespace std;

close_account::close_account():
    _stored_data{singleton::get_instance()}
{
}

close_account::~close_account()
{
}

void close_account::close(int account_number)
{
    bool is_found = false;
    int index = -1;
    for (auto account : _stored_data.accounts)
    {
        index++;
        if (account.number == account_number && account.if_open)
        {
            is_found = true;
            _stored_data.accounts[index].if_open = false; 
            cout << "The account number " << account_number << " is closed." << endl;
            break;
        }
    }
    
    if (is_found == false)
    {
        cout << "The account is either already closed or not found in the system" << endl;
    }
}