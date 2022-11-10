class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto i:s)
        {
            if(ans.length() && ans.back() == i) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};

// T.C = O(N) , S.C = O(N)
// #LeetCode Easy Way
