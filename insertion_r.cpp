#include <iostream>
using namespace std;

void insertion_r(int arr[], int n)
{
    if (n <= 1)
        return;

    insertion_r(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_r(arr, n);

    for (auto x : arr)
        cout << x << " ";

    return 0;
}