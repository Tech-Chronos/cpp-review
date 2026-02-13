#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <string.h>


// 找到中间的下标
int GetMidIndex(int* arr, int begin, int end)
{
    int mid = begin + (end - begin) / 2;
    int a = arr[begin], b = arr[mid], c = arr[end];
    if (a < b)
    {
        if (b < c)
            return mid;
        else if (a < c)
            return end;
        else
            return begin;
    }
    else
    {
        if (a < c)
            return begin;
        else if (b < c)
            return end;
        else
            return mid;
    }
}

void QuickSort_Hoare(int* arr, int begin, int end)
{
    if (begin >= end)
        return;
    int pivot_index = GetMidIndex(arr, begin, end);
    std::swap(arr[begin], arr[pivot_index]);

    int left = begin, right = end;
    while (left < right)
    {
        // 右边找小的
        while (left < right && arr[right] >= arr[begin])
        {
            --right;
        }
        // 左边找大的
        while (left < right && arr[left] <= arr[begin])
        {
            ++left;
        }

        std::swap(arr[left], arr[right]);
    }
    std::swap(arr[left], arr[begin]);

    QuickSort_Hoare(arr, begin, left - 1);
    QuickSort_Hoare(arr, left + 1, end);
}

int Partition(int* arr, int begin, int end)
{
    int mid_index = GetMidIndex(arr, begin, end);
    std::swap(arr[begin], arr[mid_index]);

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

void QuickSort_Hole(int* arr, int begin, int end)
{
    if (begin >= end)
        return;

    int index = Partition(arr, begin, end);
    QuickSort_Hole(arr, begin, index - 1);
    QuickSort_Hole(arr, index + 1, end);
}


int Partition_DoublePointer(int* arr, int begin, int end)
{
    int mid_index = GetMidIndex(arr, begin, end);
    std::swap(arr[begin], arr[mid_index]);
    int cur = begin + 1, prev = begin;
    while (cur <= end)
    {
        if (arr[cur] < arr[begin] && (++prev) != cur)
        {
            std::swap(arr[prev], arr[cur]);
        }
        ++cur;
    }
    std::swap(arr[prev], arr[begin]);
    return prev;
}

// 非递归
void QuickSort_DoublePointer(int* arr, int begin, int end)
{
    std::stack<int> st;
    st.push(begin);
    st.push(end);
    while (!st.empty())
    {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        int index = Partition_DoublePointer(arr, left, right);
        if (index + 1 < right)
        {
            st.push(index + 1);
            st.push(right);
        }
        if (index - 1 > left)
        {
            st.push(left);
            st.push(index - 1);
        }
    }
}

void _MergeSort(int* arr, int begin, int end, int* tmp)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    // 分成左右两部分
    _MergeSort(arr, begin, mid, tmp);
    _MergeSort(arr, mid + 1, end, tmp);

    // 合并
    int left1 = begin, right1 = mid;
    int left2 = mid + 1, right2 = end;
    int i = begin;

    while (left1 <= right1 && left2 <= right2)
    {
        if (arr[left1] <= arr[left2])
        {
            tmp[i++] = arr[left1++];
        }
        else
        {
            tmp[i++] = arr[left2++];
        }
    }
    while (left1 <= right1)
    {
        tmp[i++] = arr[left1++];
    }
    while (left2 <= right2)
    {
        tmp[i++] = arr[left2++];
    }
    // 拷贝到原来的区间
    std::copy(&tmp[begin], &tmp[end + 1], &arr[begin]);
    //memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* arr, int begin, int end)
{
    int* tmp = new int[end + 1];
    if (!tmp)
    {
        std::cerr << "new tmp error!" << std::endl;
        return;
    }
    _MergeSort(arr, begin, end, tmp);
    delete[] tmp;
}

void MergeSortNonR(int* a, int n)
{
    int* tmp = new int[n];
    int gap = 1;
    while (gap < n)
    {
        int i = 0;
        for (i = 0; i < n; i += gap * 2)
        {
            int left1 = i, right1 = i + gap - 1;
            int left2 = i + gap, right2 = i + 2*gap - 1;
            if (right1 >= n || left2 >= n)
            {
                break;
            }
            if (right2 >= n)
            {
                right2 = n - 1;
            }
            int j = i;
            while (left1 <= right1 && left2 <= right2)
            {
                if (a[left1] < a[left2])
                {
                    tmp[j++] = a[left1++];
                }
                else
                {
                    tmp[j++] = a[left2++];
                }
            }
            while (left1 <= right1)
            {
                tmp[j++] = a[left1++];
            }
            while (left2 <= right2)
            {
                tmp[j++] = a[left2++];
            }
            std::copy(&tmp[i], &tmp[j], &a[i]);
        }
        gap *= 2;
    }
}

int main()
{
    int original[] {2,2,4,1,9,3,5,13,7,0,8,10,16};
    // QuickSort_Hoare(original, 0, sizeof(original) / sizeof(int) - 1);
    // QuickSort_Hole(original, 0, sizeof(original) / sizeof(int) - 1);
    // QuickSort_DoublePointer(original, 0, sizeof(original) / sizeof(int) - 1);
    MergeSort(original, 0, sizeof(original) / sizeof(int) - 1);
    for (auto e : original)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
