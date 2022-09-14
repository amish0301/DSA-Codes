class Solution {
private:
    void dfs(TreeNode* &root , vector<int> f , int &ans)
    {
        // base case
        if(root == NULL) return ;
        
        f[root->val]++;   // increment the value of  frequency
        
        if(root->left == NULL && root->right == NULL) {
            int odd_cnt = 0;
            
            for(auto x : f) if(x % 2) odd_cnt++;
            
            if(odd_cnt <= 1) ans++;   // we know the palindrome is made when there is a 1 or 0 freq. of value is present. Means-> 22144 (Here 1 is only repeating Once) or 2222 (Here no value is repeating odd's time)
            
            return ;
        }
        
        dfs(root->left , f , ans);
        dfs(root->right , f , ans);
    }
        
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans= 0;
        vector<int> freq(10,0);
        dfs(root,freq,ans);
        return ans;
    }
};

// T.C = O(N) , S.C = O(1)
