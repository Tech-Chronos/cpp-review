#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int cur = 0;
        int dest = -1;
        while (cur < nums.size())
        {
            // 保证 [dest + 1, cur - 1] 的数据全都是 0
            // 遇到 0，cur++;
            // 否则 ++dest，然后交换
            if (nums[cur] == 0)
                ++cur;
            else
            {
                ++dest;
                swap(nums[dest], nums[cur++]);
            }
        }
    }
};