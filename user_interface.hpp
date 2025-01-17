#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include "open_bank.hpp"
#include "password_protection.hpp"
#include "open_new_account.hpp"
#include "csv_file_management.hpp"
#include "balance_inquiry.hpp"
#include "account_manipulations.hpp"
#include "close_account.hpp"

enum class selections 
{
    OPEN_BANK,
    OPEN_ACCOUNT,
    BALANCE_INQUIRY, 
    DEPOSIT, 
    WITHDRAWAL, 
    CLOSE_ACCOUNT, 
    PRINT_ALL, 
    EXIT
};

class user_interface
{
public:
    user_interface();
    ~user_interface();
    
    void prompt_user();
    bool exit_program();
    
protected:
    selections _transaction_type;
    open_new_account _open_account;
    csv_file_management _csv_file;
    bool _bank_open;
    balance_inquiry _balance;
    account_manipulations _account_manipulations;
    close_account _close_account;
    bool _exit_program;
};

#endif // USER_INTERFACE_HPP
