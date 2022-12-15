class Solution {
public:

    int solve(string& s1 , int i , string& s2 , int j, vector<vector<int>>& dp) {

        // base case
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1 , i-1 , s2 , j-1 , dp);

        return dp[i][j] = max(solve(s1 , i-1 , s2 , j , dp) , solve(s1 , i , s2 , j - 1 , dp));

    }
    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.length();
        int n2 = text2.length();

        // memoization for overcome the TLE
        vector<vector<int>> dp(n1 , vector<int>(n2,-1));

        return solve(text1 , n1-1 , text2 , n2-1 , dp);
    }
};

// #LeetCode Medium Way
// T.C = O(max(n1 , n2)) , S.C = O(n1*n2) + O(max(n1,n2)) [recursive Stack Space]

// here we are iterating from last idx of both the string and check it that if both char. are same then we just increment the counter for longest sequence
// another #dp
