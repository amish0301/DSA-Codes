class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length() , l = 0 , ans = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') l++;
            else l--;

            if(s[i] == ')' && s[i-1] == '(') ans += (1 << l);
        }
        return ans;
    }
};

// T.C = O(N) , S.C = O(1)
