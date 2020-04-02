#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) 
{
    if(1 == numRows)    // 一行直接返回
    {
        return s;
    }

    vector<string> rows(min(numRows, static_cast<int>(s.size())));      // 存储每行字符串
    int curRow = 0;     // 当前行
    bool goingDown = false;

    for(auto c: s)
    {
        rows[curRow] += c;
        if(0 == curRow || rows.size() - 1 == curRow)    // 顶部和底部转换方向
        {
            goingDown = !goingDown;
        }
        
        curRow += goingDown ? 1 : -1;
    }

    string str;
    for(auto sub:rows)
    {
        str += sub;
    }
    return str;
}

int main()
{
    return 0;
}

