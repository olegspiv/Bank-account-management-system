#include "user_interface.hpp"
#include "print_all.hpp"
#include "quit_program.hpp"
#include <string>
#include <iostream>

using namespace std;

user_interface::user_interface():
    _transaction_type{ selections::OPEN_BANK },
    _open_account{ },
    _csv_file{ },
    _bank_open{ false },
    _balance{ },
    _account_manipulations{ },
    _close_account{ },
    _exit_program{ false }
{
}

user_interface::~user_interface()
{
}

istream& operator>>(istream& is, selections& selection)
{
    int tmp;
    if (is >> tmp)
    {
        selection = static_cast<selections>(tmp);
    }
    
    return is;
}

void user_interface::prompt_user()
{
    if (_bank_open)
    {
        cout << "\nPlease choose what you want to do: \nOpen account (1) \nBalance inquiry (2) \nDeposit (3) \nWithdrawal (4) \nClose account (5) \nPrint all (6) \nSave the data and exit (7)\n: ";
    }
    else
    {
        cout << "\nPlease choose what you want to do: \nOpen the bank (0)\n\nActions available after bank opening:\nOpen account (1) \nBalance inquiry (2) \nDeposit (3) \nWithdrawal (4) \nClose account (5) \nPrint all (6) \nSave the data and exit (7)\n: ";
    }
    
    cin >> _transaction_type;
    double amount;
    int account_number;
    int account_pin_number;
    switch (_transaction_type)
    {
        case selections::OPEN_BANK:
        {
            if (_bank_open == false)
            {
                open_bank bank;
                if (bank.if_bank_opened())
                {
                    _bank_open = true;
                    _csv_file.restore_accounts_from_csv_file();
                }
            }
            else
            {
                cout << "The bank is already open!" << endl;
            }

            break;
        }
        
        case selections::OPEN_ACCOUNT:
        {
            if (_bank_open)
            {
                cout << "Initial deposit?: ";
                cin >> amount;
                cout << "Account pin number?: ";
                cin >> account_pin_number;
                _open_account.open_account(amount, account_pin_number);
            }
            else
            {
                cout << "Open the bank first" << endl;
            }
            
            break;
        }
        
        case selections::BALANCE_INQUIRY:
        {
            if (_bank_open)
            {
                cout << "Account number?: ";
                cin >> account_number;
                _balance.check_balance(account_number);
            }
        else
        {
            cout << "Open the bank first" << endl;
        }
            break;
        }        
        
        case selections::DEPOSIT:
        {
            if (_bank_open)
            {
                cout << "Account number?: ";
                cin >> account_number;
                cout << "Amount?: ";
                cin >> amount;
                _account_manipulations.deposit(account_number, amount);
            }
            else
            {
                cout << "Open the bank first" << endl;
            }   
            break;
        }      

        case selections::WITHDRAWAL:
        {
            if (_bank_open)
            {
                cout << "Account number?: ";
                cin >> account_number;
                cout << "Amount?: ";
                cin >> amount;
                _account_manipulations.withdraw(account_number, amount);
            }
        else
        {
            cout << "Open the bank first" << endl;
        }
            break;
        }   
        
        case selections::CLOSE_ACCOUNT:
        {
            if (_bank_open)
            {
                cout << "Account number?: ";
                cin >> account_number;
                _close_account.close(account_number);
            }
            else
            {
                cout << "Open the bank first" << endl;
            }
            
            break;
        }    

        case selections::PRINT_ALL:
        {
            if (_bank_open)
            {           
                print_all print;
            }
            else
            {
                cout << "Open the bank first" << endl;
            }
            
            break;
        }  

        case selections::EXIT:
        {   if (_bank_open)
            {           
                quit_program quit;
                _exit_program = quit.get_quit_program();
                if (_exit_program)
                {
                    cout << "Thanks for using our program!" << endl;
                }
            }
            else
            {
                cout << "Open the bank first" << endl;
            }
            
            break;
        }   
        
        default:
        {
            cout << "Wrong transaction type. Please try again." << endl;           
        }
    }
}

bool user_interface::exit_program()
{
    return _exit_program;
}