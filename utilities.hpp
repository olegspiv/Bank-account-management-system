#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <string>

using namespace std;

class utilities
{
public:
    utilities();
    ~utilities();
    
    vector<string> str_to_vec(string str, char delimiter);
    int get_index(vector<string> v, string header);
};

#endif // UTILITIES_HPP
