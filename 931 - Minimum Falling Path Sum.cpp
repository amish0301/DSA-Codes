class Solution {
public:

    int func(int i , int j , vector<vector<int>>& mat , vector<vector<int>>& dp) {

        // base case
        if(j < 0 or j >= mat[0].size()) return 1e8;

        if(i == 0) return mat[0][j];

        if(dp[i][j] != -1) return dp[i][j];


        // possible paths
        int up = mat[i][j] + func(i-1 , j , mat, dp);
        int ld = mat[i][j] + func(i-1 , j-1, mat, dp);      // Left-Diagonal
        int rd = mat[i][j] + func(i-1 , j+1 , mat, dp);     // Right-Diagonal


        return dp[i][j] = min(up , min(ld,rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size() , vector<int>(matrix[0].size() , -1));

        for(int j = 0; j < matrix[0].size(); j++) {
            ans = min(ans , func(matrix.size()-1 , j , matrix , dp));
        }

        return ans;
    }
};

// #LeetCode Medium Way
// T.C = O(N*N) + [ O(N) ] -> for going across all the col. (in main function) for finding the min value
// S.C = O(N*N) + [ O(N) ]->  for recursive stack

// My First DP Q. in which we have did Recursion -> memoization. we can convert this memoization into Tabulation for better space 
