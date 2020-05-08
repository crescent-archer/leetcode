/*
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 */

#include <iostream>
#include <unordered_map>
#include <assert.h>

using std::unordered_map;
using std::string;

int romanToInt(string s)
{
    unordered_map<string, int> umap;
    umap["I"] = 1;
    umap["IV"] = 4;
    umap["V"] = 5;
    umap["IX"] = 9;
    umap["X"] = 10;
    umap["XL"] = 40;
    umap["L"] = 50;
    umap["XC"] = 90;
    umap["C"] = 100;
    umap["CD"] = 400;
    umap["D"] = 500;
    umap["CM"] = 900;
    umap["M"] = 1000;

    size_t r = 0;

    for(size_t i = 0; i < s.size(); )
    {
        if(i + 1 < s.size())
        {
            string sub = s.substr(i, 2);
            if(umap.find(sub) != umap.end())
            {
                r += umap[sub];
                i += 2;
                continue;
            }
        }

        r += umap[string(1,s[i])];
        ++i;
    }

    return r;
}

int main()
{
    std::cout << romanToInt("MCMXCIV") << std::endl;
    return 0;
}

