#include "user_interface.hpp"

int main() 
{
    user_interface interface;
    
    while(interface.exit_program() == false)
    {
        interface.prompt_user();
    }
    return 0;
}