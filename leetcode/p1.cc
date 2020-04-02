// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// 两遍hash
vector<int> twoSum1(const vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for(size_t i = 0; i < nums.size(); ++i)
    {
       m[nums[i]] = i; 
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
            return {i, m[target - nums[i]]};
    }

    return {};
}

// 暴力
vector<int> twoSum2(const vector<int> &nums, int target)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i,j};
            }
        }
    }

    return {};
}

// 一遍hash
vector<int> twoSum3(const vector<int>&nums, int target)
{
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(m.find(target - nums[i]) != m.end()) // 此时i索引数据没有插入hash表，匹配的数据一定在i前面。
        {
            return {m[target - nums[i]], i};
        }

        m[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> sums = {5, 2, 7, 11, 15, 5};
    int target = 10;
    auto v1 = twoSum1(sums, target);
    auto v2 = twoSum2(sums, target);
    auto v3 = twoSum3(sums, target);

    for(auto it: v1)
    {
        cout << it << " ";
    }
    cout << endl;
	
    for(auto it: v2)
    {
        cout << it << " ";
    }
    cout << endl;

    for(auto it: v3)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

