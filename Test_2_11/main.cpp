#include <iostream>
#include <algorithm>

void swap(int* pa, int* pb)
{
    int tmp = *pa;
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



int main()
{
    //int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int arr[] = {8,9,1,7,2,3,5,4,6,0};
    //InsertSort(arr, sizeof(arr) / sizeof(int));
    ShellSort(arr, sizeof(arr) / sizeof(int));
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << "\n";
    return 0;
}


