/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:

    void solve(TreeNode* root , int mini , int maxi , int &sum) {
        if(root == NULL) return ;

        if(root->val >= mini && root->val <= maxi)
            sum += root->val;

       solve(root->left , mini , maxi , sum);
       solve(root->right , mini , maxi , sum);


    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root , low , high , sum);

        return sum;
    }
};

// we need to find the sum of all nodes who is lie in the Given range and just return the Total Sum.

// #LeetCode Easy Way
// T.C = O(N) , S.C = O(Height of Tree)

// #simple
