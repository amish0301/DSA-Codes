class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> mp;
        set<int> s;
        
        for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
        for(auto it: mp) s.insert(it.second);
        return s.size() == mp.size();
    }
};

// #LeetCode Easy way
// T.C = O(N) , S.C = O(N)
