#include "open_new_account.hpp"
#include <iostream>

using namespace std;

open_new_account::open_new_account():
    _stored_data{singleton::get_instance()}
{
}

open_new_account::~open_new_account()
{
}

void open_new_account::open_account(double amount, int account_pin_number)
{
    if (check_if_possible_to_open())
    {
        account account;
        account.if_open = true;
        account.balance = amount;
        account.account_pin_number = account_pin_number;
        
        if (_stored_data.accounts.size() >= 1)
        {
            account.number = _stored_data.accounts.back().number + 1;
        }
        else
        {
            account.number = 1001;
        }
        _stored_data.accounts.push_back(account);
        cout << "The account number " << account.number << " was opened." << endl;
    }
}

bool open_new_account::check_if_possible_to_open()
{
    bool possible_to_open = true;
    int cnt;
    for (auto account : _stored_data.accounts)
    {
        if (account.if_open)
        {
            cnt++;
        } 
        if (cnt >= 100)
        {
            cout << "The maximal number of open accounts is reached" << endl; 
            possible_to_open = false;
            break;
        }
    }
    return possible_to_open;
}