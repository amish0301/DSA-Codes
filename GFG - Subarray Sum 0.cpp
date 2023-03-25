class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int sum = 0 , ans = 0;
        
        for(int i = 0 ; i < n; i++) {
            
            sum += a[i];
            
            if(sum == 0) ans = i+1;
            
            if(mp.find(sum) != mp.end())
                ans = max(ans , i - mp[sum]);
            else
                mp[sum] = i;
        }
        
        return ans;
    }
};
