#include <iostream>
#include <algorithm>

template <class T>
void swap(T* pa, T* pb)
{
    T tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

// 5 2 4 6 1 3
// 2 4 5 1 6 3
void InsertSort(int* arr, size_t len)
{
    for (int i = 1; i < len; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >=0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void ShellSortV1(int* arr, size_t len)
{
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        // 对gap分组，插入排序
        for (int i = gap; i < len; ++i)
        {
            int key = arr[i];
            int j = i - gap;
            while (j >= 0 && key < arr[j])
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}

void ShellSort(int* arr, size_t len)
{
    int gap = 1;
    while (gap < len / 3)
    {
        gap = (gap * 3) + 1;
    }

    while (gap > 0)
    {
        for (size_t i = gap; i < len; ++i)
        {
            int j = i - gap;
            int key = arr[i];
            while (j >= 0 && arr[j] > key)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
        gap /= 3;
    }
}

void SelectSort(int* arr, size_t len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        int index = i;
        int j = i + 1;
        while (j < len)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
            ++j;
        }
        if (index != i)
            swap(&arr[index], &arr[i]);
    }
}

void SelectSort_Bi(int* arr, size_t len)
{
    int left = 0, right = len - 1;
    while (left < right)
    {
        int maxindex = left;
        int minindex = left;
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] > arr[maxindex])
            {
                maxindex = i;
            }
            if (arr[i] < arr[minindex])
            {
                minindex = i;
            }
        }

        swap(&arr[minindex], &arr[left]);

        if (maxindex == left)
            maxindex = minindex;

        swap(&arr[maxindex], &arr[right]);
        ++left;
        --right;
    }
}

// 向下调整
void AdjustDown(int* arr, int parent, int n)
{
    int child = (parent * 2) + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child + 1] > arr[child])
        {
            ++child;
        }
        if (arr[parent] < arr[child])
        {
            swap(&arr[parent], &arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

// 向上调整
void AdjustUp(int* arr, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (arr[child] > arr[parent])
        {
            swap(&arr[child], &arr[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

// 升序建大堆
//void HeapSort(int* arr, int n)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        AdjustUp(arr, i);
//    }
//    for (int j = n - 1; j >= 0; --j)
//    {
//        swap(&arr[0], &arr[j]);
//        AdjustDown(arr, 0, j);
//    }
//}
void HeapSort(int* arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        AdjustDown(arr, i, n);
    }
    for (int j = n - 1; j >= 0; --j)
    {
        swap(&arr[0], &arr[j]);
        AdjustDown(arr, 0, j);
    }
}

int main()
{
    int arr[] = {8,9,1,7,2,3,5,4,6,0};
//    InsertSort(arr, sizeof(arr) / sizeof(int));
//    ShellSort(arr, sizeof(arr) / sizeof(int));
//    SelectSort(arr, sizeof(arr) / sizeof(int));
//    SelectSort_Bi(arr, sizeof(arr) / sizeof(int));
    HeapSort(arr, sizeof(arr) / sizeof(int));
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}


