#include <iostream>

class Solution
{
private:
    int helper(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            int tmp = num % 10;
            sum += (tmp * tmp);
            num /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n)
    {
        int slow = helper(n);
        std::cout << slow << std::endl;
        int fast = helper(slow);
        std::cout << fast << std::endl;
        // 快指针每次走一步，慢指针每次走两步
        while (slow != fast)
        {
            slow = helper(slow);
            fast = helper(fast);
            fast = helper(fast);
        }
        if (fast == 1)
            return true;
        else
            return false;
    }
};