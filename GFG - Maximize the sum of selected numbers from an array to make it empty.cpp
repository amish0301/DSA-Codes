class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int map[100001] = {0};
        for(int i = 0; i < n; i++) {
            map[a[i]]++;
        }
        
        int sum = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            int curr = a[i];
            if(map[curr] != 0) {
                sum += curr;
                map[curr]--;
                if(map[curr-1] != 0) map[curr-1]--;
            }
        }   
        return sum;
    }
};

// T.C = O(N) , S.C = O(N) || O(100001) ~= O(1)

// Q. is simple that we need to find the max sum from selected no.
// We start the iteration from the last idx of arr and check if it's freq. is > 0 then we'll add that value in our sum and delete the freq. of that value by 1.
// and also delete the freq. of (curr-1) val. from freq. array if and only if it's freq. must be not 0.

// Level : Medium
