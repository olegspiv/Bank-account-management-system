#ifndef CSV_FILE_MANAGEMENT_HPP
#define CSV_FILE_MANAGEMENT_HPP

#include "singleton.hpp"
#include "utilities.hpp"
#include <ostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class csv_file_management
{
public:
    csv_file_management();
    ~csv_file_management();
    void restore_accounts_from_csv_file();
    void save_accouts_to_csv_file();

protected:
    singleton &_stored_data;
    ofstream _accounts_csv_file;  
    string _csv_file_name;
    utilities _utilities;
    
    const string CSV_FILENAME = "bank_accounts.csv";
    const char DELIMITER = ';';
};

#endif // CSV_FILE_MANAGEMENT_HPP
