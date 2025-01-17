#ifndef BALANCE_INQUIRY_HPP
#define BALANCE_INQUIRY_HPP

#include "singleton.hpp"

class balance_inquiry
{
public:
    balance_inquiry();
    ~balance_inquiry();

    void check_balance(int account_number);
    
protected:
    singleton &_stored_data;
};

#endif // BALANCE_INQUIRY_HPP
