class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int n = nums.size();
	    int ans = 0;
	    
	    for(int j = 1; j < n-1; j++) {
	        
	        // calculate no. of smaller ele. in left part of j
	        int leftSmaller = 0 , rightGreater = 0;
	        
	        for(int i = j-1; i>=0; i--) {
	           if(nums[i] < nums[j]) leftSmaller++;    
	        }
	        
          // calculate no. of Greater ele. in right part of j
	        for(int k = j+1; k < n; k++) {
	            if(nums[k] > nums[j]) rightGreater++;
	        }
	        
	        ans += (leftSmaller * rightGreater);  // observation Based Eq.
	    }
	    
	    return ans;
	}
};

// #GFG Medium Way
// T.C = O(N^2) , S.C = O(1)

// Just Observation and Constraints are Helpful
