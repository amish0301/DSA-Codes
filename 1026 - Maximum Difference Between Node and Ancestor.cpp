class Solution {
public:

    int dfs(TreeNode* root , int maxi , int mini) {

        if(!root) return abs(maxi - mini);

        // updating the max and min values at every subtrees
        maxi = max(root->val , maxi);
        mini = min(root->val , mini);

        return max(dfs(root->left , maxi , mini) , dfs(root->right , maxi , mini));
    }

    int maxAncestorDiff(TreeNode* root) {
        int mx = 0 , mn = INT_MAX;
        return dfs(root , mx , mn);
    }
};

// #LeetCode Medium Way
// T.C = O(N) , S.C = O(H)

// here we are maintaining the max and min value at each an every node and just return the max diff. between them
