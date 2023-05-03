#include <iostream>
using namespace std;

void buildMaxHeap(int arr[], int n)
{
    for (int i; i < n; i++)
    {
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = 1;

            while (arr[j] > arr[(j - 1) / 2])
            {
                swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        // sawp first indexes
        swap(arr[0], arr[i]);

        int j = 0, index;

        do
        {
            index = 2 * j + 1;

            if (arr[index] < arr[index + 1] && index < (i - 1))
            {
                index++;
            }

            if (arr[j] < arr[index] && index < i)
            {
                swap(arr[j], arr[index]);
            }

            j = index;
        } while (index < i);
    }
}

int main()
{
    int arr[] = {10, 20, 15, 17, 9, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
}