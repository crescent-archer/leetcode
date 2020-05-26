#include <iostream>
#include <vector>

using std::vector;

int removeElement(vector<int>& nums, int val) {
    int curIndex = 0;
    for(size_t i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != val)
        {
            nums[curIndex++] = nums[i];
        }
    }
    return curIndex;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

