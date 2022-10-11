class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX , n2 = INT_MAX;
        for(auto i : nums) {
            if(i <= n1) n1 = i;
            else if(i <= n2) n2 = i;
            else return true;
        }
        return false;
    }
};

// Just apply Pure Logic that check previous stored smaller values are smaller then 3rd curr. value then it's follow the condition
// T.C = O(N) , S.C = O(1)

// Level : Medium
