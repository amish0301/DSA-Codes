Q. Link : https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> ans(n,0);
        int sum = 0;
        
        for(int i = 0; i < n; i++) if(!(nums[i] & 1)) sum += nums[i];
        
        for(int i = 0; i < n; i++) {
            
            int idx = q[i][1] , val = q[i][0];
            int oldVal = nums[idx];
            nums[idx] += val;    // add the val
            
            bool wasEven = (oldVal % 2 == 0);
            bool nowEven = (nums[idx] % 2 == 0);
            
            if(wasEven && nowEven) {
                ans[i] = sum + val;
                sum += val;
            }
            else if(wasEven && !nowEven) {
                ans[i] = sum - oldVal;
                sum -= oldVal;
            }
            else if(!wasEven && nowEven) {
                ans[i] = sum + nums[idx];
                sum += nums[idx];
            }
            else 
                ans[i] = sum;
        }
        return ans;
    }
};

// T.C = O(N) , S.C = O(1)
