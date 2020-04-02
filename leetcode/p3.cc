// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 自己想的，应该算是官方说的滑动法
int lengthOfLongestSubstring(const string &s) 
{
    int left = 0;       // 左边位置
    int right = 0;      // 右边位置
    int lsg = 0;        // 最大值

    while(right < s.size())
    {
        string sub = s.substr(left, right - left);
        if(sub.find(s[right]) != string::npos)  // 查到值，这里字串没有重复字符
        {
            left = left + sub.find(s[right]) + 1;   // 左边位置右移到查到字符的后一个位置 
        }
        
        ++right;
        lsg = (right - left > lsg ) ? right - left : lsg; // 判断最大值
    }

    return lsg;
}

// hashmap,好像差不多，就是把字符串查找改成hash查找
int lengthOfLongestSubstring1(const string &s) 
{
    int left = 0;
    int right = 0;
    int lsg = 0;
    unordered_map<char, int> m;

    while(right < s.size())
    {
        if(m.find(s[right]) != m.end() && left <= m[s[right]])
        {
            left = m[s[right]] + 1;
        }

        m[s[right]] = right;
        ++right;
        lsg = (right - left > lsg ) ? right - left : lsg;
    }

    return lsg;
}

int main()
{
    string s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s) << std::endl;
    std::cout << lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
    return 0;
}

