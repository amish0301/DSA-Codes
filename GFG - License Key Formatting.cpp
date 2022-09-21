class Solution
{
   public:
    string ReFormatString(string s, int k){
    	
    int n = s.length();
    string ans;
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
      
        if(s[i] == '-') continue;

        if(s[i] >= 'a' && s[i] <= 'z')
            ans.push_back(toupper(s[i]));
        else
            ans.push_back(s[i]);

        cnt++;
        
        if(cnt == k) {
            ans.push_back('-');
            cnt = 0;
        }
    }
        reverse(ans.begin(), ans.end());
        if(ans[0] == '-') ans.erase(ans.begin() + 0);
        return ans;
    }
};

// T.C = O(N) , S.C = O(1)

// here you have to make a k group of Strings and after taking k char. from string you have to seprate the 2 groups by using "-".
// there is a condition that 1st group contain < k char. also. so that's why we have start taking the char. from the last indecx of String and whatever char. left at the end that will be taken.
// after that Just reverse the string and that is your ans.
