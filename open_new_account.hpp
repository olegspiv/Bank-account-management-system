#ifndef OPEN_NEW_ACCOUNT_HPP
#define OPEN_NEW_ACCOUNT_HPP

#include "singleton.hpp"

class open_new_account
{
public:
    open_new_account();
    ~open_new_account();
    
    void open_account(double amount, int account_pin_number);
    
protected:
    singleton &_stored_data;
    bool check_if_possible_to_open();
};

#endif // OPEN_NEW_ACCOUNT_HPP
