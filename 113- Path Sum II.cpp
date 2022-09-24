class Solution {
private:
    void helper(TreeNode* &root, int target , vector<int> &path , vector<vector<int>> &ans) {
        if(!root) return ;
        
        path.push_back(root->val);
        if(!root->left && !root->right && target == root->val) ans.push_back(path);
        
        helper(root->left,target - root->val , path , ans);
        helper(root->right,target-root->val , path ,ans);
        
        path.pop_back();    // backtracking
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        helper(root,targetSum,path,ans);
        return ans;
    }
};

// Here we need to find the path sum from root to Leaf Node which is equal to TargetSum.
// So Here we have used the backtracking and DFS Approach.

// T.C = O(N) : N = all the Nodes 
// S.C = O(N*M) ; we have made 2D Vector.
