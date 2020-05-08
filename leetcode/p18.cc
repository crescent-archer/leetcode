/*
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>

using std::vector;
using std::string;
using std::unordered_multimap;
using std::pair;
using std::multiset;
using std::set;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    if(nums.size() < 4)
    {
        return {};
    }

    sort(nums.begin(), nums.end());
    set<vector<int>> results;

    unordered_multimap<int, pair<size_t, size_t>> ummap;
    for(size_t i = 0; i < nums.size() - 1; ++i)
    {
        for(size_t j = i + 1; j < nums.size(); ++j)
        {
            ummap.insert({nums[i] + nums[j], {i, j}});
        }
    }
    
    for(auto it = ummap.begin(); it != ummap.end();++it)
    {
        auto range = ummap.equal_range(target - it->first);
        for(auto i = range.first; i != range.second; ++i)
        {
            if(i->second.first != it->second.first && i->second.first != it->second.second 
               && i->second.second != it->second.first && i->second.second != it->second.second)
            {
                multiset<int> mset{nums[i->second.first], nums[i->second.second], nums[it->second.first], nums[it->second.second]};
                vector<int> vr(mset.begin(), mset.end());
                results.insert(vr);
            }
        }
    }

    
    return vector<vector<int>>(results.begin(), results.end());
}

int main()
{
    return 0;
}

