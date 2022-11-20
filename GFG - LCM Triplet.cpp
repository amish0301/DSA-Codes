class Solution {
  public:
    long long lcmTriplets(long long N) {
        if(N<=2) return N;
        
        // for odd case
        if((N&1) == 1) return N*(N-1)*(N-2);
        
        // even but multiple of 3
        if(N%3 == 0) return (N-2)*(N-1)*(N-3);
        
        return N*(N-1)*(N-3);
    }
};

// T.C = O(logN) , S.C = O(logN)
// #GFG medium way

// observation Based  (Mean to say we've to find the max LCM so start from last and decrement by 1 so we'll get max LCM)
