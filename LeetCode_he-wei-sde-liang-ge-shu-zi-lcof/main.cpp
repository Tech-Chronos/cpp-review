#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        int left = 0, right = price.size() - 1;
        vector<int> retvec;
        while (left < right)
        {
            if (price[left] + price[right] > target)
            {
                --right;
            }
            else if (price[left] + price[right] < target)
            {
                ++left;
            }
            else
            {
                retvec.emplace_back(price[left]);
                retvec.emplace_back(price[right]);
                break;
            }
        }
        return retvec;
    }
};