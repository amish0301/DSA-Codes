class Solution {
public:
    int maxLength(vector<string>& arr , string str = "" , int idx = 0) {
        
        // making set to check if any char. is repeat or not in curr. string
        unordered_set<char> s(str.begin() , str.end());

        // base case
        if(s.size() != ((int)str.length())) return 0;

        int len = str.length();

        for(int i = idx; i < arr.size(); i++) {
            len = max(len , maxLength(arr,str+arr[i],i+1));
        }

        return len;
    }
};

// Leetcode Medium
// T.C = O(N) , S.C = O(N*sizeOfEvryString) + O(N)[Auxillary Stack Space]
