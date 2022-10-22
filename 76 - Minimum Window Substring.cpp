class Solution {
public:
    string minWindow(string s, string t) {
        int begin = 0 , end = 0 , windowSize = INT_MAX;
        int counter = t.size(), head = 0;

        vector<int> map(128,0);
        for(auto it : t) map[it]++;     // mapped every char. of t

        while(end < s.size()) {

            // if curr. char. is present in t string
            if(map[s[end++]]-- > 0) counter--;

            while(counter == 0) {
                if((end-begin) < windowSize) windowSize = end - (head=begin);   // head is used to preserve the begin idx
                if(map[s[begin++]]++ == 0) counter++;     // make it invalid or kind of Backtracking
            }
        }

        return windowSize == INT_MAX ? "" : s.substr(head,windowSize);
    }
};

/*

#LeetCode HARD Problem
Concept Used : Sliding Window

T.C = O(m + n) : where n = Size of str s , m = Size of str t
S.C = O(128) ~ O(1)

Approach:
Step 1 : map all the Char. of String t
Step 2 : take two ptr which is used for Window
Step 3 : if curr. char's freq. is > 0 then deceament the counter.  (we need to find the min. window len so min. len is possible to Size of String t so counter is intiallised with size of t)
Step 4 : once counter is 0 it means that can be our ans. so count the window len by (end-begin) ptr. and update windowsize.
Step 5 : increment the begin idx by 1 and increment their char. freq. by 1 to make it as before.

*/
