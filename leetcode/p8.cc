#include <iostream>
#include <string>
#include <ctype.h>
#include <limits.h>

using namespace std;

int myAtoi(string str) 
{
    if(str.empty())
    {
        return 0;
    }

    int i = 0;
    while(isblank(str[i]))
    {
        ++i;
    }
    
    int flag = 1;
    if(str.empty() ||((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'))
    {
        return 0;
    }

    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            flag = -1;
        }
        ++i;
    }

    if(str.empty() || str[i] < '0' || str[i] > '9')
    {
        return 0;
    }

    long ret = 0;
    while(!str.empty() && isdigit(str[i]))
    {
        ret = ret * 10 + str[i++] - 48;
        if(ret > INT_MAX)
        {
            return (flag == 1) ? INT_MAX : INT_MIN;
        }
    }

    return flag * ret;
}

int main()
{
    std::cout << myAtoi("-91283472332") << std::endl; 
    return 0;
}

