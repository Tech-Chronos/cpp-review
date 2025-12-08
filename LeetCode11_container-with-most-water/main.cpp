#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int maxV = 0, tmpV = 0;
        int left = 0, right = height.size() - 1;
        // 高度是由矮的决定的
        // 每次计算一次V，然后排出掉矮的那个
        // 因为对于矮的来说，继续向内遍历：宽度肯定变小，高度如果比我大，就不变；
        // 比我小，就变小，所以面积一定变小
        // 对于高的来说，向内便利：宽度变小，高度如果如果比现在的小的高度大，高度就变大了，所以不能排除
        while (left < right)
        {
            // 1. 高度由左边的决定
            if (height[left] < height[right])
            {
                tmpV = height[left] * (right - left);
                ++left;
            }
                // 2. 高度由右边决定
            else
            {
                tmpV = height[right] * (right - left);
                --right;
            }
            if (tmpV > maxV)
                maxV = tmpV;
        }
        return maxV;
    }
};
