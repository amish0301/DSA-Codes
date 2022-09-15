class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        
        int n = nums.size();
        if(n & 1) return ans;
        sort(nums.begin() , nums.end());
        
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        
        for(int i = 0; i < n ; i++) {
            if(mp[nums[i]] == 0) continue;
            if(mp[nums[i] * 2] == 0) return {};
            
            // means everything is cleared
            ans.push_back(nums[i]);
            mp[nums[i]]--;          // decrease the freq. of original number
            mp[nums[i] * 2]--;          // decrease the freq. of doubled number
            
        }
        
        return ans;
    }
};
