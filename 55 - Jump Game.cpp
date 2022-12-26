class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int idx_to_reach = n-1;

        for(int i = n - 1; i >=0; i--) {
            
            int curr_idx = i;
            int jump = nums[i];

            if(curr_idx + jump >= idx_to_reach) idx_to_reach = curr_idx; 
        }

        return idx_to_reach == 0;
    }
};

// #LeetCode Medium Way
// T.C = O(N) , S.C = O(1)

// Sometimes we have to think reverse or do reverse engineering mean to say u know result so can we go from result to basic if it's possible then we can go basic to result
