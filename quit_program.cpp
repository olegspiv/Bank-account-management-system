#include "quit_program.hpp"

quit_program::quit_program():
    _csv_file{ },
    _quit_program{ false }
{
    if (if_access_granted())
    {
        _csv_file.save_accouts_to_csv_file();
        _quit_program = true;
    }
}

quit_program::~quit_program()
{
}

bool quit_program::get_quit_program()
{
    return _quit_program;
}