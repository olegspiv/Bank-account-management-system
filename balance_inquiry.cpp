#include "balance_inquiry.hpp"
#include "singleton.hpp"
#include "iostream"

using namespace std;

balance_inquiry::balance_inquiry():
    _stored_data{singleton::get_instance()}
{
}

balance_inquiry::~balance_inquiry()
{
}

void balance_inquiry::check_balance(int account_number)
{
    bool is_found = false;
    for (auto account : _stored_data.accounts)
    {
        if (account.number == account_number && account.if_open)
        {
            cout << "The account number " << account_number << " has " << account.balance << "$." << endl;
            is_found = true;
            break;
        }
    }
    
    if (is_found == false)
    {
        cout << "The account is either closed or not found in the system" << endl;
    }
}