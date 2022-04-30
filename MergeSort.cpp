// T.C = O(nlogn) , S.C = O(n)

/*Approch:
    first divide array in two part
    sort an array seprately
    combine both the array
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int *arr , int s , int e)
{
    int mid = (s+e)/2;

    // find length of 2 new array
    int len1 = mid - s + 1;
    int len2 = e - mid;
    
    // create 2 new Dynamically Array 
    int *first = new int[len1];
    int *second = new int[len2];

    // copying value in 1st array
    int mainArrayidx = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayidx++];
    }
    // copying value in 2nd array
    mainArrayidx = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayidx++];
    }

// merge 2 sorted arrays

    // create index
    int idx1 = 0;
    int idx2 = 0;
    mainArrayidx = s;

    while (idx1 < len1 && idx2 < len2)
    {
        if(first[idx1] < second[idx2])
        {
            arr[mainArrayidx++] = first[idx1++];
        }
        else
        {
            arr[mainArrayidx++] = second[idx2++];
        }
    }

    // checking, if first arry of size is lesser so check sepratly
    while (idx1 < len1)
        arr[mainArrayidx++] = first[idx1++];
    while (idx1 < len1)
        arr[mainArrayidx++] = second[idx2++];

    // deleting Heap Memory 
    delete[] first;
    delete[] second;
}

void mergesort(int *arr, int s, int e)
{
    if(s>=e)
        return;
    int mid  = (s+e)/2;

    // solve left part of array
    mergesort(arr, 0, mid);

    // solve right part
    mergesort(arr , mid+1 , e);

    merge(arr, s, e);
}

int main()
{

    int arr[5] = {1,5,4,3,2};
    int n = 5;

    mergesort(arr, 0 ,n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}