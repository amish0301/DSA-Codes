class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        
    	 for(int i = 0; i < N; i++) {
    	    maxi = max(maxi,A[i]);
    	    mini = min(mini , A[i]);
    	}
    	
    	return maxi + mini;
    }

};

// T.C = O(N) , S.C = O(1)
#Simpool
