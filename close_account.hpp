#ifndef CLOSE_ACCOUNT_HPP
#define CLOSE_ACCOUNT_HPP

#include "singleton.hpp"

class close_account
{
public:
    close_account();
    ~close_account();

    void close(int account_number);
    
protected:
    singleton &_stored_data;
};

#endif // CLOSE_ACCOUNT_HPP
