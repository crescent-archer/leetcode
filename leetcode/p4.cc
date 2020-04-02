#include <iostream>
#include <vector>

using namespace std;

// 迭代,自己刚开始写的，优点蠢，O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    bool flag = (nums1.size() + nums2.size()) % 2;    // 奇数

    int p1 = 0, p2 = 0;     // nums1和nums2位置
    int res = 0;
    int h_pos = (nums1.size() + nums2.size()) / 2;
    while((p1 + p2) <= h_pos && p1 < nums1.size() && p2 < nums2.size())
    {
        if(p1 + p2 == h_pos)
        {
            if(flag)
            {
                return min(nums1[p1], nums2[p2]);
            }
            else
            {
                return (res + min(nums1[p1], nums2[p2])) / 2.0;
            }
        }
        else
        {
            res = min(nums1[p1], nums2[p2]);
            if(nums1[p1] < nums2[p2])
            {
                ++p1;
            }
            else
            {
                ++p2;
            }
        }
    }

    if(p1 < nums1.size())
    {
        if(flag)
        {
            return nums1[h_pos - p2];
        }
        else
        {
            if(h_pos - p2 - 1 >= 0)
            {
                res = max(res, nums1[h_pos - p2 -1 ]);
                return (res + nums1[h_pos - p2]) / 2.0; 
            }
            return (res + nums1[h_pos - p2]) / 2.0;
        }
    }
    else
    {
        if(flag)
        {
            return nums2[h_pos - p1];
        }
        else
        {
            if(h_pos - p1 - 1 >= 0)
            {
                res = max(res, nums2[h_pos - p1 -1 ]);
                return (res + nums2[h_pos - p1]) / 2.0;
            }
            return (res + nums2[h_pos - p1]) / 2.0;
        }
    }
}

// 迭代，借鉴别人的写法，O(m+n)
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) 
{
    size_t p1 = 0;     // nums1位置
    size_t p2 = 0;     // nums2位置
    int vleft = 0;  // 左值
    int vright = 0; // 右值
    size_t half = (nums1.size() + nums2.size()) / 2;   // 中位数位置

    while(p1 + p2 < half)   
    {
        vleft = vright;
        if(p2 >= nums2.size() || (p1 < nums1.size() && nums1[p1] < nums2[p2]))        // p1移位条件
        {
            vright = nums1[p1++];
        }
        else        // p2移位
        {
            vright = nums2[p2++];
        }
    }

    if(half % 2)    // 奇数
    {
        return vright;
    }

    return (vleft + vright) / 2.0;
}

// 获取第k大的数
int getKth(const vector<int> &nums1, const vector<int> &nums2, int k)
{
    if(nums1.size() > nums2.size()) // 保证没有数据的一定是nums1
    {
        return getKth(nums2, nums1, k);
    }

    if(nums1.empty())
    {
        return nums2[k -1];
    }

    if(1 == k)
    {
        return min(nums1[0], nums2[0]);
    }
    
    int i = min(static_cast<int>(nums1.size()), k / 2);
    int j = min(static_cast<int>(nums2.size()), k / 2);

    if(nums1[i - 1] > nums2[j - 1])
    {
        return getKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
    }
    else
    {
        return getKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
    }
}

// 获取第k大的数
int getKth1(const vector<int> &nums1, const vector<int> &nums2, int k)
{
    auto v1 = nums1;
    auto v2 = nums2;

    while(1)
    {
        if(v1.size() > v2.size())
        {
            swap(v1, v2);
        }

        if(v1.empty())
        {
            return v2[k - 1];
        }

        if(1 == k)
        {
            return min(v1[0], v2[0]);
        }

        int i = min(static_cast<int>(v1.size()), k / 2);
        int j = min(static_cast<int>(v2.size()), k / 2);

        if(v1[i - 1] > v2[j - 1])
        {
            v2 = vector<int>(v2.begin() + j, v2.end());
            k = k - j;
        }
        else
        {
            v1 = vector<int>(v1.begin() + i, v1.end());
            k = k - i;
        }
    }
}

// 二分法，第k大，O(log(m+n))
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) 
{
    int left = (nums1.size() + nums2.size() + 1) / 2;
    int right = (nums1.size() + nums2.size() + 2) / 2;
    
    if(left == right)
    {
        return getKth(nums1, nums2, left);
    }
    return (getKth(nums1, nums2, left) + getKth(nums1, nums2, right)) / 2.0;
}



int main()
{   
    vector<int> v1{1,2};
    vector<int> v2{3,4};
    std::cout << findMedianSortedArrays2(v1, v2) << std::endl;
    return 0;
}

