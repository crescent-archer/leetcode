#include <iostream>
#include <climits>
#include <string>


using namespace std;

int reverse(int x) 
{
    long ret = 0;

    while(x != 0)
    {
        int r = x % 10;     // 余数
        ret = ret * 10 + r;
        x /= 10;
    }
    if(ret > INT_MAX || ret < INT_MIN)
        return 0;

    return ret;
}

int main()
{
    cout << INT_MAX << endl;
    cout << reverse(1534236469) << endl;
    
    
    return 0;
}

