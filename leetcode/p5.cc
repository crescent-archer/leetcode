#include <iostream>
#include <string>

using namespace std;

// cbbd
// 最长回文子串,暴力
string longestPalindrome(string s) 
{
    if(s.empty())
        return "";

    int left = 0;
    int right = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        for(int j = i + 1; j < s.size(); ++j)
        {
            int k = i;
            for(; k <= (i + j) / 2; ++k)
            {
                if(s[k] != s[j - k + i])
                {
                    break;
                }
            }
            if(k > (i + j) / 2 && right - left < j - i)
            {
                left = i;
                right = j;
            }
        }
    }
    return s.substr(left, right - left + 1);
}

// cbbd
// 动态规划
string longestPalindrome1(const string &s) 
{
	if(s.empty())
    {
        return "";
    }

    int left = 0;
    int right = 0;

    int dp[s.size()];
    // 从后往前
    for(int i = s.size() - 1; i >= 0; --i)
    {
        dp[i] = 1;
        for(int j = s.size() - 1; j > i; --j)
        {
            if(1 == dp[j - 1] && s[i] == s[j])
            {
                dp[j] = 1;
                if(right - left <= j - i)
                {
                    right = j;
                    left = i;
                }
            }
            else
            {
                dp[j] = 0;
            }
        }
    }
    return s.substr(left, right - left + 1);
}

// 中心扩展
int expandAroundCenter(string s, int left, int right)
{
    while(left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }

    return right - left - 1;
}

// 中心扩展求最长子序列
string longestPalindrome2(const string &s) 
{
    if(s.empty())
    {
        return "";
    }

    int left = 0;       
    int right = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        int len1 = expandAroundCenter(s, i, i);    // 奇数
        int len2 = expandAroundCenter(s, i, i + 1);// 偶数
        int len = max(len1, len2);
        if(len > right - left + 1)
        {
            left = i - (len - 1)/ 2;
            right = i + len / 2;
        }
    }

    return s.substr(left, right - left + 1);
}

int main()
{
    std::cout << longestPalindrome1("abcba") << std::endl;
    return 0;
}

// a b c b a
// 
// 
// 
//         1
// 
// dp[i][j]是回文的条件是：dp[i][j] == dp[i][i] && dp[i + 1][j - 1] > 0;
// a b a b a
// 1 0 3 0 1
//   1 0 3 0
//     1 0 3
//       1 0
//         1
// 
// c b b d 
// 
//       
//       1
