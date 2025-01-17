#include "utilities.hpp"
#include <fstream>
#include <algorithm>

utilities::utilities()
{
}

utilities::~utilities()
{
}

vector<string> utilities::str_to_vec(string str, char delimiter)
{
    vector<string> str_vec;
    string temp;
    for (auto element : str)
    {
        if (element != delimiter)
        {
            temp += element;
        }
        else
        {
            str_vec.push_back(temp);
            temp = "";
        }
    }
    str_vec.push_back(temp);
    return str_vec;
}

int utilities::get_index(vector<string> v, string header) 
{ 
    auto it = find(v.begin(), v.end(), header); 
  
    if (it != v.end())  
    { 
        int index = it - v.begin();
        return index;
    } 
    else 
    { 
        throw "Header not found";
    } 
} 