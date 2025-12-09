#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0;
        // 1. 先固定最大的数字
        for (int i = nums.size() - 1; i > 1; --i)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                // 对于次大的数和最小的数相加大于最大的数
                // 那么对于次大的数字来说，都能和比他小的数字与最大的数字组成三角形
                // 所以对于次大的数字与最大的数字来说就有right - left 个数字可以组成三角形
                if (nums[left] + nums[right] > nums[i])
                {
                    ret += (right - left);
                    --right;
                }
                else
                {
                    // 如果次大的数字和最小的数字相加小于最大的数字
                    // 那么对于最小的数字来说就不能和比他大的任意一个数字与最大的数组成三角形，就++left；
                    ++left;
                }
            }
        }
        return ret;
    }
};