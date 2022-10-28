class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // base case
        if(strs.size() == 1) return {{strs[0]}};

        vector<vector<string>> ans;
        unordered_map<string , vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(strs[i].begin() , strs[i].end());

            mp[strs[i]].push_back(s);
        }

        // traverse on map
        for(auto i = mp.begin(); i != mp.end(); i++) {
            ans.push_back(i -> second);
        }

        return ans;
    }
};

// T.C = O(N * MlogM) : M = str[i].length , S.C = O(N)
// #LeetCode Medium
