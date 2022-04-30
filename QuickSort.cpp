/*
T.C = O(nlogn) , S.C = O(n)
Approch:
    --> to do partition
    --> Sort Left part (Bounded Belowby by pivotIndex) and Right part (Bounded above by pivotIndex) one by one
*/

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    // first count the How many numbers are lesser than our partitioned number
    int pivot = arr[s], cnt = 0;
    for (int i = s + 1; i <= e; i++)
        if (arr[i] <= pivot)
            cnt++;

    // place pivot right side
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    // handling left and right part
    int i = s, j = e; // take two pointer to sort 
    while(i < pivotIndex && j > pivotIndex)
    {
        // if any ele. which is already less than our pivot ele.
        while (arr[i] < arr[pivotIndex])
            i++;
        
        // same for jth ele.
        while(arr[j] > arr[pivotIndex])
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
        
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;
    int p = partition(arr, s, e); // it will return index

    // sort left part
    quickSort(arr, s, p - 1);

    // sort right part
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[] = {2, 3, 5, 1, 4};
    int n = 5;

    quickSort(arr, 0, n-1);

    // print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}