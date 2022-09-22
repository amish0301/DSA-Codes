class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(j == n  || s[j] == ' ')
            {
                reverse(s.begin()+i , s.begin()+j);
                i = j+1;
            }
        }
        return s;
    }
};
