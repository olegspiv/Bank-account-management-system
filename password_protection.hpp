#ifndef PASSWORD_PROTECTION_HPP
#define PASSWORD_PROTECTION_HPP

#include <string>

using namespace std;

class password_protection
{
public:
    password_protection();
    ~password_protection();

protected:
    string enter_encrypted_password();
    bool if_access_granted();
    
    bool _access_granted;
    
    const string PASSWORD = "1234";
};

#endif // PASSWORD_PROTECTION_HPP
