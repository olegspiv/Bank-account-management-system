#ifndef OPEN_BANK_HPP
#define OPEN_BANK_HPP

#include "password_protection.hpp"
#include <string>

using namespace std;

class open_bank: public password_protection
{
public:
    open_bank();
    ~open_bank();

    bool if_bank_opened();

protected:    
    bool _bank_opened;
};

#endif // OPEN_BANK_HPP
