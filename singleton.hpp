#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include <vector>

using namespace std;

struct account
{
    bool if_open = false;
    double balance = 0.0;
    int number = 0;
    int account_pin_number = 0;
};

class singleton
{

protected:
    singleton() = default;

public:
    vector<account> accounts;
    static singleton& get_instance()
    {
       static singleton instance;
       return instance;
    }
    
    singleton(const singleton&) = delete; // for copy constructor
    singleton(singleton&&) = delete; // for move constructor
    singleton& operator = (const singleton&) = delete; // for copy assignment operator
    singleton& operator = (const singleton&&) = delete; // for move assignment operator
};
 
#endif // SINGLETON_HPP
