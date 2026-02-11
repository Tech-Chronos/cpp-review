#include <iostream>
#include <algorithm>

void swap(int* pa, int* pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void InsertSort(int* arr, size_t len)
{
    for (int i = 1; i < len; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    InsertSort(arr, sizeof(arr));
    for (auto e : arr)
    {
        std::cout << e;
    }
    std::cout << "\n";
    return 0;
}
