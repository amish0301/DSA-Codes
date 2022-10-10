class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        int i = 0;

        if(i == n - 1) return "";
        
        while(i < n/2) {
            if(palindrome[i] - 'a' != 0) {
                palindrome[i] = 'a';
                return palindrome;
            }
            i++;
        }
        
        // if u reached over here means there is still palindrome
        palindrome[n-1] += 1;
        return palindrome;
    }
};

// T.C = O(N/2) , S.C = O(1)
