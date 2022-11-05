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
private:
TreeNode* helper(vector<int>& preorder , int preStart , int preEnd , vector<int>& inorder , int inStart , int inEnd , unordered_map<int,int> &mp) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRootIdx = mp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = helper(preorder,preStart+1 , preStart+numsLeft , inorder , inStart , inRootIdx-1 , mp);
    root->right = helper(preorder,preStart+numsLeft+1 , preEnd , inorder , inRootIdx+1 , inEnd , mp);

    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = helper(preorder,0,preorder.size() - 1 , inorder , 0 , inorder.size()-1 , mp);
        return root;
    }
};
