#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Sort
{
private:
    static int GetMidIndex(std::vector<int>& arr, int begin, int end)
    {
        int mid = begin + (end - begin) / 2;
        int a = arr[begin], b = arr[mid], c = arr[end];

        if (a < b)
        {
            if (b < c) return mid;
            else if (a < c) return end;
            else return begin;
        }
        else
        {
            if (a < c) return begin;
            else if (b < c) return mid;
            else return end;
        }
    }
private:
    static void AdjustDown(std::vector<int>& arr, int parent, int size)
    {
        int child = (parent * 2) + 1;
        while (child < size)
        {
            if (child + 1 < size && arr[child + 1] > arr[child])
            {
                child++;
            }
            if (arr[child] > arr[parent])
            {
                std::swap(arr[child], arr[parent]);
                parent = child;
                child = (parent * 2) + 1;
            }
            else
            {
                break;
            }
        }
    }

    static int Partition_Hoare(std::vector<int>& arr, int begin, int end)
    {
        int pivot_index = GetMidIndex(arr, begin, end);
        std::swap(arr[pivot_index], arr[begin]);
        int left = begin, right = end;

        while (left < right)
        {
            while (left < right && arr[right] >= arr[begin])
            {
                --right;
            }
            while (left < right && arr[left] <= arr[begin])
            {
                ++left;
            }

            std::swap(arr[left], arr[right]);
        }
        std::swap(arr[begin], arr[left]);
        return left;
    }


    static void QuickSort_Hoare(std::vector<int>& arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int index = Partition_Hoare(arr, begin, end);
        QuickSort_Hoare(arr, begin, index - 1);
        QuickSort_Hoare(arr, index + 1, end);
    }

    static int Partition_Holei(std::vector<int>& arr, int begin, int end)
    {
        // 找中间值，交换
        int mid_index = GetMidIndex(arr, begin, end);
        std::swap(arr[mid_index], arr[begin]);

        // 拿到中间值，第一个是洞
        int holei = begin;
        int pivot = arr[begin];

        int left = begin, right = end;
        while (left < right)
        {
            while (left < right && arr[right] >= pivot)
            {
                --right;
            }
            arr[holei] = arr[right];
            holei = right;

            while (left < right && arr[left] <= pivot)
            {
                ++left;
            }
            arr[holei] = arr[left];
            holei = left;
        }
        arr[holei] = pivot;
        return holei;
    }

    static void QuickSort_Holei(std::vector<int>& arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int index = Partition_Holei(arr, begin, end);
        QuickSort_Holei(arr, begin, index - 1);
        QuickSort_Holei(arr, index + 1, end);
    }

    // 双指针
    static int Partition_Lumto(std::vector<int>& arr, int begin, int end)
    {
        int mid_index = GetMidIndex(arr, begin, end);
        std::swap(arr[mid_index], arr[begin]);
        int pivot = arr[begin];

        int prev = begin, cur = begin + 1;
        while (cur <= end)
        {
            if (arr[cur] < pivot && (++prev != cur))
            {
                std::swap(arr[prev], arr[cur]);
            }
            ++cur;
        }
        std::swap(arr[prev], arr[begin]);
        return prev;
    }

    static void QuickSort_Lumto(std::vector<int>& arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int index = Partition_Lumto(arr, begin, end);
        QuickSort_Lumto(arr, begin, index - 1);
        QuickSort_Lumto(arr, index + 1, end);
    }

    static void QuickSort_Lumto_NonR(std::vector<int>& arr, int begin, int end)
    {
        if (begin >= end)
            return;
        std::stack<int> st;
        st.push(begin);
        st.push(end);
        while (!st.empty())
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            int index = Partition_Lumto(arr, left, right);
            if (left < index - 1)
            {
                st.push(left);
                st.push(index - 1);
            }

            if (index + 1 < right)
            {
                st.push(index + 1);
                st.push(right);
            }
        }
    }

public:
    // 插入排序
    static void InsertSort(std::vector<int>& arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            int key = arr[i];
            int j = i - 1;
            for (; j >= 0; --j)
            {
                if (arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j + 1] = key;
        }
    }

    // 希尔排序
    static void ShellSort(std::vector<int>& arr)
    {
        int gap = 1;
        int size = (int)arr.size();
        while (gap < size / 3)
        {
            gap = gap * 3 + 1;
        }

        while (gap > 0)
        {
            for (int i = gap; i < size; ++i)
            {
                int key = arr[i];
                int j = i - gap;
                for (; j >= 0; j -= gap)
                {
                    if (arr[j] > key)
                    {
                        arr[j + gap] = arr[j];
                    }
                    else
                    {
                        break;
                    }
                }
                arr[j + gap] = key;
            }
            gap /= 3;
        }
    }

    static void SelectSort(std::vector<int>& arr)
    {
        int n = (int)arr.size();
        for (int i = 0; i < n / 2; ++i)
        {
            int max_index = i;
            int min_index = i;
            // 注意这里是小于 n - i
            for (int j = i; j < n - i; ++j)
            {
                if (arr[max_index] < arr[j])
                {
                    max_index = j;
                }
                if (arr[min_index] > arr[j])
                {
                    min_index = j;
                }
            }

            std::swap(arr[min_index], arr[i]);

            if (max_index == i)
            {
                max_index = min_index;
            }
            std::swap(arr[max_index], arr[n - i - 1]);
        }
    }

    static void HeapSort(std::vector<int>& arr)
    {
        int n = (int)arr.size();
        // 向下建堆
        // 找第一个非叶子节点
        for (int i = (n - 1 - 1) / 2; i >= 0; --i)
        {
            AdjustDown(arr, i, n);
        }

        for (int j = n - 1; j >= 0; --j)
        {
            std::swap(arr[0], arr[j]);
            AdjustDown(arr, 0, j);
        }
    }

    static void BubbleSort(std::vector<int>& arr)
    {
        int n = (int)arr.size();
        for (int i = 0; i < n - 1; ++i)
        {
            bool exchange = false;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    exchange = true;
                }
            }
            if (!exchange)
                break;
        }
    }

    static void _QuickSort_Hoare(std::vector<int>& arr)
    {
        QuickSort_Hoare(arr, 0, (int)arr.size() - 1);
    }

    static void _QuickSort_Holei(std::vector<int>& arr)
    {
        QuickSort_Holei(arr, 0, (int)arr.size() - 1);
    }

    static void _QuickSort_Lumto(std::vector<int>& arr)
    {
        QuickSort_Lumto(arr, 0, (int)arr.size() - 1);
    }

    static void _QuickSort_Lumto_NonR(std::vector<int>& arr)
    {
        QuickSort_Lumto_NonR(arr, 0, (int)arr.size() - 1);
    }
};


int main()
{
    std::vector<int> original {8,9,1,7,2,3,5,4,6,0};
    // Sort::InsertSort(original);
    // Sort::ShellSort(original);
    // Sort::SelectSort(original);
    // Sort::HeapSort(original);
    // Sort::BubbleSort(original);
    // Sort::_QuickSort_Hoare(original);
    // Sort::_QuickSort_Holei(original);
    Sort::_QuickSort_Lumto_NonR(original);

    for (auto e : original)
    {
        std::cout << e << " ";
    }
    std::cout << "\n";

    return 0;
}
