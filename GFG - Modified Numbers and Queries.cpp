class Solution {
  public:
    int sumOfAll(int l, int r){
        int ans = 0;
        vector<bool> isPrime(r+1 , true);
        
        // seive concept
        for(int i = 2; i <= r; i++) {
            if(isPrime[i])
                for(int j = i*i; j <= r; j += i)
                    isPrime[j] = false;
        }
        
        while(l <= r) {
            
            if(l == 1) {
                l++;
                ans++;
                continue;
            }
            
            int currSum = 0;
            
            for(int i = 2; i <= l; i++) {
                if(isPrime[i] && l % i == 0) currSum += i;
            }
            
            ans += currSum;
            l++;
        }
        
        return ans;
    }
};

// here we have to find the Sum of all the Prime factors of a Particular Value in the Given range.
// T.C = O(nlog(logn)) , S.C = O(r + 1) : r = range where end.
