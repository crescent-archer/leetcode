/*
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 */
#include <iostream>
#include <vector>

#include <assert.h>

using std::vector;
using std::min;

// 暴力，不用脑子 n^2，超时
int maxArea(vector<int>& height) 
{
    assert(height.size() > 1);
    size_t max_area = 0;
    for(size_t i = 0; i < height.size() - 1; ++i)
    {
        for(size_t j = i + 1; j < height.size(); ++j)
        {
           size_t area =  (j - i) * min(height[i], height[j]);
           max_area = area > max_area ? area : max_area;
        }
    }

    return max_area;
}

// 双指针
int maxArea2(vector<int>& height)
{
    assert(height.size() > 1);
    size_t i = 0;
    size_t j = height.size() - 1; // 头尾索引
    size_t max_area = 0;
    
    while(i < j)
    {
        size_t minHeight = height[i] < height[j] ? height[i++] : height[j--];  
        
        max_area = minHeight * (j - i + 1) > max_area ? (j - i + 1) * minHeight : max_area;
    }
    
    return max_area;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

