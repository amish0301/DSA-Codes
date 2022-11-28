
/* ************************************ A VERY VERY GOOD PROBLEM ON "Kadane's Algo" *********************************************************/

class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	  
	    int currSum = 0 , maxSum = 0;
	    int maxSum_StartIdx = 0, maxSum_EndIdx = 0;
	    int currSum_StartIdx = 0;
	    
	    for(int i = 0; i < n; i++) {
	        
	        // as we know that we don't have to consider the -ve values so neglect it
	        if(a[i] < 0) {
	            currSum = 0;
	            currSum_StartIdx = i + 1;
	            
	        }else currSum += a[i];
	        
	        
	        // Updating maxsum
	        if(currSum > maxSum) {
	            maxSum = currSum;
	            maxSum_StartIdx = currSum_StartIdx;     // bcoz our maxSum is currSum 
	            maxSum_EndIdx = i+1;
	            
	        }else if(currSum == maxSum) {
	            
	            int currDist = i + 1 - currSum_StartIdx;
	            int maxSumDist = maxSum_EndIdx - maxSum_StartIdx;
	            
	            
	            if(currDist > maxSumDist) {
	                
	                // update our maxsum
	                maxSum_StartIdx = currSum_StartIdx;
	                maxSum_EndIdx = i + 1;
	                
	            }
	        }
	    }
	   
	   
	    vector<int> ans;
	   
	   	// now we have to return the Subarray of Maximum Sum
	    for(int i = maxSum_StartIdx; i < maxSum_EndIdx; i++) ans.push_back(a[i]);
	    
	    return ans.size() == 0 ? {-1} : ans;
	}
};

// #GFG Medium Way
// T.C = O(N) , S.C = O(1)

// Concept: KADANE'S Algo for finding the maxSum of Subarray in O(N) Time Complexity
