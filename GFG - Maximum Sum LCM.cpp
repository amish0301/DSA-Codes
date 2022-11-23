class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        long ans = 0;
        for(int i = 1; i <= sqrt(n); i++)
            if(n % i == 0) {
                ans += i;
                if(n/i != i) ans += (n/i);
            }
            
        return ans;
    }
};

// #GFG Easy Way
// T.C = O(sqrt(n)) , S.C = O(1)

// we have to find max sum so and it's clearly stated that all number must be unique so we have to take all number from 1 to n who is divisible to N
