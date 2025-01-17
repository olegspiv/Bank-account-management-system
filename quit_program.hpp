#ifndef QUIT_PROGRAM_HPP
#define QUIT_PROGRAM_HPP

#include "csv_file_management.hpp"
#include "password_protection.hpp"

class quit_program: public password_protection
{
public:
    quit_program();
    ~quit_program();

    bool get_quit_program();
    
protected:
    csv_file_management _csv_file;
    bool _quit_program;
};


#endif // QUIT_PROGRAM_HPP
