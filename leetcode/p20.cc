//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
#include <iostream>
#include <stack>

using std::stack;
using std::string;

// 括号匹配一看到就应该是用栈了
bool isValid(string s)
{
    stack<char> cstack;
    for(size_t i = 0; i < s.size(); ++i)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            cstack.push(s[i]);
        }
        else if(cstack.empty() || (s[i] == '}' && cstack.top() != '{') || (s[i] == ']' && cstack.top() != '[') || (s[i] == ')' && cstack.top() != '('))
        {
            return false;
        }
        else
        {
            cstack.pop();
        }
    }

    if(cstack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

