#include <iostream>

bool isPalindrome(int x) 
{
    int y = x;
    if(x < 0)
    {
        return false;
    }

    long ret = 0;

    while(y)
    {
        ret = ret * 10 + y % 10;
        y = y / 10;
    }

    if(x == ret)
    {
        return true;
    }

    return false;
}

// 官方题解翻转一半，且没有溢出问题
bool isPalindrome1(int x) 
{
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    
    int ret = 0;
    while(x > ret)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }

    return ret == x || ret / 10 == x;
}

int main()
{
    return 0;
}

