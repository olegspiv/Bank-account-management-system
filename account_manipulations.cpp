#include "account_manipulations.hpp"
#include "iostream"

using namespace std;

account_manipulations::account_manipulations():
    _stored_data{singleton::get_instance()}
{
}

account_manipulations::~account_manipulations()
{
}

void account_manipulations::withdraw(int account_number, double amount)
{
    bool is_found = false;
    int index = -1;
    for (auto account : _stored_data.accounts)
    {
        index++;
        if (account.number == account_number && account.if_open)
        {
            is_found = true;
            if (account.balance >= amount)
            {
                _stored_data.accounts[index].balance -= amount;
                cout << "The account number " << account_number << " has " << _stored_data.accounts[index].balance << "$ after the withdrawal of " << amount << "$." << endl;
            }
            else
            {
                cout << "No sufficient funds on the accound number " << account_number << endl;
                break;
            }
        }
    }
    
    if (is_found == false)
    {
        cout << "The account is either closed or not found in the system" << endl;
    }
}

void account_manipulations::deposit(int account_number, double amount)
{
    bool is_found = false;
    int index = -1;
    for (auto account : _stored_data.accounts)
    {
        index++;
        if (account.number == account_number && account.if_open)
        {
            _stored_data.accounts[index].balance += amount;
            cout << "The account number " << account_number << " has " << _stored_data.accounts[index].balance << "$ after the deposit of " << amount << "$." << endl;
            is_found = true;
            break;
        }
    }
    
    if (is_found == false)
    {
        cout << "The account is either closed or not found in the system" << endl;
    }
}