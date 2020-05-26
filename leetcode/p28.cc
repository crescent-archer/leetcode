#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int strStr(string haystack, string needle)
{
    for(size_t i = 0; i < haystack.size(); ++i)
    {
        size_t j = 0;
        int index = i;
        for(; j < needle.size(); ++j)
        {
            if(haystack[index++] != needle[j])
            {
                break;
            }
        }
        if(needle.size() == j)
        {
            return index - j; 
        }
    }

    return -1;
}

// next数组含义
// 当失配之后向右移动的位数
// next数组的值为最长匹配前缀
void getNext(string p, int *next)
{
    int pLen = p.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < pLen - 1)
    {
        if(-1 == k || p[j] == p[k])
        {
            ++k;
            ++j;
            if(p[j] == p[k])
            {
                next[j] = k;
            }        
            else
            {
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
}

int kmp(string s, string p)
{
    if(p.empty())
    {
        return 0;
    }

    int i = 0;
    int j = 0;
    int sLen = s.size();
    int pLen = p.size();
    int *next = new int[pLen];
    getNext(p, next);

    while(i < sLen && j < pLen)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    delete []next;

    if(j == pLen)
    {
        return i - j;
    }

    return -1;
}

int main()
{
    string s = "asdsdfasdsnvsdabcdabcfsafa";
    string p = "abcdabc";
    int next[p.size()];
    getNext(p, next);
    
    for(auto n: next)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << kmp(s, p) << std::endl;

    return 0;
}

