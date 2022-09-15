
// T.C = O(nlogn) , S.C = O(1)

class Solution{
    public:
    int minSubset(vector<int> &a,int n){
        sort(a.begin() , a.end());
        
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        
        long long currSum = 0;
        int cnt = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            
            if(currSum > sum) break;
            currSum += a[i];
            sum -= a[i];
            cnt++;
            
        }
        
        return cnt;
    }
};

// We need to make SUM Greater using Min. Element so Algo is Below
Algo:
/*
    1. sort the Array
    2. bcoz we need to also check that whatever no. we picked other than that number we need to do sum for that so we first count the sum of all ele.
    3. we will be iterating from the last index and add that ele. into our currSum and check at any moment if currSum > previous calculated Sum  then we don't need to procces ahead.
    4. increment the counter of the every value which we are considering as in the sum.
*/
