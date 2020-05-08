/*
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 */
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void appendString(string *arr, string digits, string r, vector<string>& v);

vector<string> letterCombinations(string digits)
{
    if(digits.empty())
    {
        return {};
    }
    string letters[8] = {
        "abc", 
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> result;
    appendString(letters, digits, "", result);

    return result;
}

void appendString(string *arr, string digits, string r, vector<string>& v)
{
    if(r.size() == digits.size())
    {
        v.push_back(r);
        return;
    }

    for(size_t i = 0; i < arr[digits[r.size()] - 50].size(); ++i)
    {
        appendString(arr, digits, r + string(1, arr[digits[r.size()] - 50][i]), v);
    }
}

int main()
{
    vector<string> r;
    r = letterCombinations("23");

    for(auto s: r)
    {
        std::cout << s << std::endl;
    }

    return 0;
}

