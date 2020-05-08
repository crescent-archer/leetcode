/*
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool isMatch(const string &s, const string &p)
{
    if(p.empty())
    {
        return s.empty();
    }

    bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

    if(p.size() >= 2 && p[1] == '*')
    {
        return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    }
    else
    {
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
}

int main()
{
    bool b = isMatch("s", "i*s");
    cout << boolalpha << b << endl;
    return 0;
}

