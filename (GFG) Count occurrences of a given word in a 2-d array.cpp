class Solution{
    private:
    void helper(vector<vector<char>> &mat , string target , int i , int j , int idx , int &ans) 
    {
        // base case
        if(i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || idx == target.length() || mat[i][j] != target[idx])
            return ;
            
        if(idx == target.length() - 1) {
            ans++;
            return;
        }
        char saveChar = mat[i][j];  // bcoz we temporary remove that char. from that index bcoz to make sure that we don't use that again and again and get out from the infinity loop
        mat[i][j] = '0';
        
        helper(mat,target,i+1,j,idx+1,ans);
        helper(mat,target,i-1,j,idx+1,ans);
        helper(mat,target,i,j+1,idx+1,ans);
        helper(mat,target,i,j-1,idx+1,ans);
        
        mat[i][j] = saveChar;
    }
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                helper(mat,target,i,j,0,ans);
            }
        }
        return ans;
    }
};
