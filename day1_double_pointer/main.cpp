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

    // 复写 0
    void duplicateZeros(vector<int>& arr)
    {
        int cur = 0;
        int dest = -1;
        // 1. 先找到最后一个要复写的数字
        while(cur < arr.size())
        {
            if (arr[cur] != 0)
            {
                ++dest;
                cout << dest << endl;
            }
            else
            {
                dest += 2;
                cout << dest << endl;
            }
            if (dest < arr.size() - 1)
                ++cur;
            else
                break;
        }

        // 如果最后一个是复写的 0，并且越界了，要做特殊处理
        if (dest == arr.size())
        {
            arr[dest - 1] = 0;
            dest -= 2;
            --cur;
        }

        //往前复写，画图
        while(dest >= 0)
        {
            if (arr[cur] != 0)
            {
                arr[dest] = arr[cur];
                --dest;
            }
            else
            {
                arr[dest] = arr[dest - 1] = 0;
                dest -= 2;
            }
            --cur;
        }
    }
};

int main()
{
    // vector 的size是size_t类型的
    vector<int> v = {1,0,2,3,0,4,5,0};
    int i = -1;

    cout << decltype(v.size())(i) << endl;
    cout << (i < v.size()) << endl;
    return 0;
}