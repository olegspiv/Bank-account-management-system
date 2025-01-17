#include "password_protection.hpp"
#include <iostream>
#include <algorithm>
#include <conio.h>

password_protection::password_protection():
    _access_granted{ false }
{
    string password = enter_encrypted_password();
    if (password != PASSWORD)  
    {
        cout << "Wrong pin number!" << endl;
    }
    else
    {
        cout << "Access granted" << endl;
        _access_granted = true;
    }
}

password_protection::~password_protection()
{
}

string password_protection::enter_encrypted_password()
{
    int character; 
    string password;
    cout << "Please input the special pin number: ";
    character = getch();
        
    while (character != 13) // loop until enter key is not pressed (13 is the ASCII value of enter key)
    {
        if (character == 8) //(8 is the ASCII value of backspace key)
        {
            if (password.length()) 
            {
                cout << "\b \b";
                password.pop_back();
            }
            character = getch();
            continue;
        }
        password.push_back(character);
        cout << '*';
        character = getch();
    }
    cout << '\n';
    return password;
}

bool password_protection::if_access_granted()
{
    return _access_granted;
}