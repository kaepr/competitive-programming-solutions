#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivot = arr[e];
    int index = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index], arr[e]);

    return index;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot, end);
}

int main()
{

    vector<int> arr = {5, 1, 9, 3, 2, 8, 7, 11, 4, 15, 8};

    cout << arr.size() << "\n";

    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    quicksort(arr, 0, 10);

    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}