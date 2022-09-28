class Solution{
public:
    
    bool isFit(int arr[], int brr[], int n){
        sort(arr , arr + n);
        sort(brr , brr+n);
        
        for(int i = n-1; i >= 0; i--) if(arr[i] > brr[i]) return false;
        
        return true;
    }
};

/*
Q. Geek is given two arrays arr[] and brr[] of the same size n. The array arr[] will be said to fit in array brr[] if by arranging the elements of both arrays, there exists a solution such that i'th element of arr[] is less than or equal to i'th element of brr[], for each i, 0 <= i < n. Help Geek find if the given array arr[] will fit in array brr[] or not.

T.C = O(nlogn) , S.C = O(1)

*/
