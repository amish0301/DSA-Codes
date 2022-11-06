class Solution {
public:
    string orderlyQueue(string s, int k) {

        if(k == 1) {

            int n = s.length();
            string doubleString = s+s;
            string ans = s;

            for(int i = 1; i < n; i++) {
                string str = doubleString.substr(i,n);      // we are removing 1 by 1 intial char. and make new string
                if(str < ans) ans = str;
            }

            return ans;
        }

        sort(s.begin() , s.end());
        return s;
    }
};

// T.C = O(NlogN) , Auxilliary S.C = O(2N)
