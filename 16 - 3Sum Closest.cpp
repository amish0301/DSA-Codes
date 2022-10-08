class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      
        // sort the array
        sort(begin(nums) , end(nums));

        int min_diff = INT_MAX;
        int sum = 0 , n = nums.size() , ans = 0;

        for(int i = 0; i < n - 2; i++) {

            int s = i + 1 , e = n - 1;
            while(s < e) {
                sum = nums[s] + nums[i] + nums[e];

                if(abs(target-sum) < min_diff) {
                    min_diff = abs(target-sum);
                    ans = sum;
                }

                if(sum > target) e--;
                else s++;
            }
        }
        return ans;
    }
};

// T.C = O(NlogN) + O(N) = O(NlogN)
// S.C = O(1)
