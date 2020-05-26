#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <assert.h>
#include <limits.h>


int divi(unsigned a, unsigned b)
{
    if(a < b) return 0;
    
    unsigned t = b;
    int i = 1;
    while(a >= (t << 1) && (t << 1) <= INT_MAX)
    {
        t <<= 1;
        i <<= 1;
    }

    return i + divi(a - t, b);
}

int divide(int dividend, int divisor)
{
    assert(divisor);
    if(-1 == divisor && dividend == INT_MIN) return INT_MAX;
    if(dividend == divisor) return 1; // 防止INT_MIN INT_MIN的情况

    unsigned a = abs(dividend);
    unsigned b = abs(divisor);
    int sdividend = (dividend >> 31) & 0x1; // 不知道是算数右移还是逻辑右移，不能保证移位为-1
    int sdivisor = (divisor >> 31) & 0x1;
    int s = sdividend ^ sdivisor; // 符号位 0 或 1 
    s = s ? -1 : 1; // 1->-1 或 0->1，

    return s * divi(a, b);
}

int main()
{
    std::cout << divide(-2147483648, 2) << std::endl;
    return 0;
}

