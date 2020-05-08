/*
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 */
#include <iostream>
#include <assert.h>
#include <unordered_map>

using std::string;
using std::unordered_map;

string intToRoman(int num)
{
    assert(num < 4000 && num > 0);

    unordered_map<int, string> umap;
    umap[1] = "I";
    umap[5] = "V";
    umap[10] = "X";
    umap[50] = "L";
    umap[100] = "C";
    umap[500] = "D";
    umap[1000] = "M";
    string r;

    int i = 1000;
    while(i)
    {
        int j = num / i;
        num %= i;
        
        if(j)
        {
            if(j == 9)
            {
                r += umap[i] + umap[i * 10];
                j = 0;
            }
            else if(j >= 5)
            {
                r += umap[i * 5] ;
                j -= 5;
            }

            if(j == 4)
            {
                r += umap[i] + umap[i * 5];
            }
            else
            {
                for(int k = 0; k < j; ++k)
                {
                    r += umap[i]; 
                }
            }
        }
        i /= 10;
    }

    return r;
}


/* I II III IV V VI VII VIII IX X
 * XI XII XIII XIV XV XVI XVII XVIII XVIV XX
 * 
 *
 *
 *
 */


int main()
{
    std::cout << intToRoman(3999) << std::endl;
    std::cout << intToRoman(1994) << std::endl;
    return 0;
}

