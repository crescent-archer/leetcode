/*
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。
 * 返回这三个数的和。假定每组输入只存在唯一答案。
 *
 */

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using std::string;
using std::vector;

int threeSumClosest(vector<int>& nums, int target)
{
    assert(nums.size() > 2);

    int result = INT_MAX;
    sort(nums.begin(), nums.end());

    for(size_t i = 0; i < nums.size() - 2; ++i)
    {
        size_t l = i + 1;
        size_t r = nums.size() - 1;

        while(l < r)
        {
            if(abs(nums[i] + nums[l] + nums[r] - target) < abs(result))
            {
                result = nums[i] + nums[l] + nums[r] - target;
            }
            else if(nums[i] + nums[l] + nums[r] - target > 0)
            {
                --r;
            }
            else
            {
                ++l;
            }
            
        }
    }

    return result + target;
}

/*
 *
 *  target 2
 *  -10 -8 -7 -3 1  9
 *
 */

int main()
{
    vector<int> v = {-1, 2, 1, -4};
    std::cout << threeSumClosest(v, 2) << std::endl;
    return 0;
    
}

