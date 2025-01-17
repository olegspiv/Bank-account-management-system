#include "open_bank.hpp"

#include <iostream>

using namespace std;

open_bank::open_bank():
    _bank_opened { false }
{
    if (if_access_granted())
    {
        cout << "The bank was opened" << endl;
        _bank_opened = true;  
    }
}

open_bank::~open_bank()
{
}

bool open_bank::if_bank_opened()
{
    return _bank_opened;
}
