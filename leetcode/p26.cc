#include <iostream>
#include <vector>

using std::vector;

int removeDuplicates(vector<int>& nums) {
    int curIndex = 0;

    for(size_t i = 0; i < nums.size();)
    {
        int n = nums[i++];
        while(i < nums.size() && nums[i] == n) ++i;
        nums[curIndex++] = nums[i - 1];
    }

    return curIndex;
}

int main()
{
    vector<int> nums = {1,1,2};
    int i = removeDuplicates(nums);
    for(int j = 0; j < i; ++j)
    {
        std::cout << nums[j] << std::endl;
    }
    return 0;
}

