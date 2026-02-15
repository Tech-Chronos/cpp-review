#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int left = i + 1, right = nums.size() - 1;

            while (left < right)
            {
                if (nums[left] + nums[right] + nums[i] > 0)
                {
                    --right;
                }
                else if (nums[left] + nums[right] + nums[i] < 0)
                {
                    ++left;
                }
                else
                {
                    vv.push_back({nums[left], nums[right], nums[i]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }

                    while (left < right && nums[right] == nums[right - 1])
                    {
                        --right;
                    }

                    if (left < right)
                    {
                        ++left;
                        --right;
                    }
                    else
                        break;
                }


            }

            while (nums[i] == nums[i + 1] && i < nums.size() - 2)
            {
                ++i;
            }
        }
        return vv;
    }
};
