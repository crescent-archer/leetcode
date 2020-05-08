//
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::string;
using std::vector;
using std::stack;

void generate(string str, int left, int right, vector<string>& v)
{
    if(right == 0)
    {
        v.push_back(str);
        return;
    }

    if(left >= right)
    {
        generate(str + "(", left - 1, right, v);
    }
    else
    {
        if(left > 0)
        {
            generate(str + "(", left - 1, right, v);

            generate(str + ")", left, right - 1, v);
        }
        else
        {
            generate(str + ")", left, right - 1, v);
        }
    }
}

vector<string> generateParenthesis(int n)
{
    if(n == 0)
    {
        return {};
    }
    vector<string> v;

    generate("", n, n, v);
    return v;
}

int main()
{
    vector<string> v;
    v = generateParenthesis(3);
    for(auto s: v)
    {
        std::cout << s << std::endl;
    }
    return 0;
}

