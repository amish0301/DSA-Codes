class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;

        // Edge cases
        if(k <= 0) return false;
        if(k >= n) k = n - 1;

        for(int i = 0; i < n; i++) {
            // if window is increased by our k value then start to remove ele. from starting
            if(i > k) s.erase(nums[i-k-1]);
            if(s.find(nums[i]) != s.end()) return true;

            s.insert(nums[i]);
        }
        return false;
    }
};

// Short Discussion : Very Nice Q. , in the begining it's not Intuitive but if we obeserved that in q. we need to check repeated ele. is exist or not so from this point we can used SET bcoz SET is used to store Unique Ele.

// T.C = O(n) , S.C = O(n) => auxillary spaced used and in worst case it's O(n) 
