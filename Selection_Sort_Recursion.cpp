#include<bits/stdc++.h>
using namespace std;

void selsort(int *arr , int n)
{
    if(n == 1 || n == 0)
        return;

    for (int i = 1; i < n; i++)
    {
        if(arr[i-1] > arr[i])
            swap(arr[i - 1], arr[i]);
    }
    selsort(arr, n - 1);
}

int main(){

    int arr[8] = {1, 4, 3, 2, 8 , 5, 7 , 6};

    selsort(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}