/*
 *
 *
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.empty())
    {
        return "";
    }

    size_t minSize = strs[0].size();

    for(size_t i = 1; i < strs.size(); ++i)
    {
        minSize = strs[i].size() < minSize ? strs[i].size() : minSize;
    }

    size_t i = 0;
    for(; i < minSize; ++i)
    {
        char c = strs[0][i];
        bool flag = false;
        for(size_t j = 1; j < strs.size(); ++j)
        {
            if(c != strs[j][i])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }

    return strs[0].substr(0, i);
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

