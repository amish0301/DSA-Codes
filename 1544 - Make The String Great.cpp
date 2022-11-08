class Solution {
public:
    string makeGood(string s) {
       for(int i = 1; i < s.length(); i++) {
           if(abs(s[i-1] - s[i]) ==  32) {
               s.erase(i-1,2);
               i = max(0,i-2);
           }
       }

       return s;
    }
};

// #LeetCode Easy Way
// T.C = O(N) , S.C = O(1)
