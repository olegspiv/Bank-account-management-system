#ifndef ACCOUNT_MANIPULATIONS_HPP
#define ACCOUNT_MANIPULATIONS_HPP

#include "singleton.hpp"

class account_manipulations
{
public:
    account_manipulations();
    ~account_manipulations();
    
    void withdraw(int account_number, double amount);
    void deposit(int account_number, double amount);
    
protected:
    singleton &_stored_data;    
};

#endif // ACCOUNT_MANIPULATIONS_HPP
