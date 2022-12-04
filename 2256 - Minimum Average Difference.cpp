class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        // counting the sum of all ele. bcoz of we need sum from -> i+1 to n 
        long totalSum = 0;
        for(int i = 0; i < nums.size(); i++) totalSum += nums[i];


        int minAvg = INT_MAX , index = -1, rightPart = 0;
        long prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {

            // calculating prefix sum for sum till ith idx
            prefixSum += nums[i];

            // EDGE CASE: if i = n - 1 then our denominator becomes 0 so it will become INFINITY
            // here we did sum - prefixSum bcoz if we subtract sum till ith form total sum then we get i+1 to nth sum in only one pass

            if(i != nums.size() - 1) rightPart = (totalSum - prefixSum) / (nums.size() - i -1);
            else rightPart = 0;

            int diff = abs( (prefixSum/(i+1)) - rightPart);

            // finding minimum avg
            if(diff < minAvg) {
                minAvg = diff;
                index = i;
            }

        }
        
        return index; 
    }
};

/*

Intuition:
just observe the TestCases and u realised that we just need sum of till ith ele. and we know that Prefix Sum Algo is used for finding the sum till ith ele.

Approach:

Step 1: find the sum of all array elements.
  
Step 2: make prefixSum variable which will store the sum of till ith elements.

Step 3: calculate the abs diff and find the minimmum diff. among them and also store the index which is gonna be returned.

Complexity:
Time complexity: O(N)
Space complexity: O(1)
  
*/
