#include "csv_file_management.hpp"
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

csv_file_management::csv_file_management():
    _stored_data{singleton::get_instance()},
    _accounts_csv_file(),
    _utilities{ }
{
}

csv_file_management::~csv_file_management()
{
}

void csv_file_management::restore_accounts_from_csv_file()
{
     fstream fin;
     fin.open(CSV_FILENAME, ios::in);
     if (fin)
     {       
        vector<string> row;
        vector<string> headers;
        string line;
        account account;
        int cnt = -1;
    
        while (fin >> line)
        {
            cnt++;
            if (cnt == 0)
            {
                headers = _utilities.str_to_vec(line, DELIMITER);
            }
            else
            {
                row = _utilities.str_to_vec(line, DELIMITER);
                istringstream(row[_utilities.get_index(headers, "if_open")]) >> account.if_open;
                account.balance = stod(row[_utilities.get_index(headers, "balance")]);
                account.number = stoi(row[_utilities.get_index(headers, "number")]);
                account.account_pin_number = stoi(row[_utilities.get_index(headers, "pin_number")]);
                _stored_data.accounts.push_back(account);
            }
        }
     }
}

void csv_file_management::save_accouts_to_csv_file()
{
    _accounts_csv_file.open(CSV_FILENAME, ofstream::trunc);
    _accounts_csv_file << "if_open;balance;number;pin_number" << endl;
    
    for (size_t index = 0; index < _stored_data.accounts.size(); index++)
    {
        _accounts_csv_file << _stored_data.accounts[index].if_open << DELIMITER 
        << _stored_data.accounts[index].balance << DELIMITER 
        << _stored_data.accounts[index].number << DELIMITER 
        << _stored_data.accounts[index].account_pin_number << endl;
        //_stored_data.accounts[index].if_open = false; //close all accounts while exiting
    }
}