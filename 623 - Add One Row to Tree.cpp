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
int cnt = 1;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      
        // base case
        if(root == NULL) return root;

        // Edge case
        if(cnt == 1 && depth == 1) {
            TreeNode* newNode = new TreeNode(val);  // here we create node
            newNode->left = root;
            root = newNode;
        }

        if(cnt == depth - 1) {
            
            // storing left and right part bcoz to prevent the Lost of subtree.
            TreeNode* leftTree = root->left; 
            TreeNode* rightTree = root->right;

                TreeNode* newLeft = new TreeNode(val);  
                if(root->left) {
                    root->left = newLeft;
                    newLeft -> left = leftTree;
                }else root->left = newLeft;         // if left subtree is Null then attach directly that value.

                TreeNode* newRight = new TreeNode(val);
                if(root->right) {
                    root->right = newRight;
                    newRight -> right = rightTree;
                }else root->right = newRight;

        }

        cnt++;
        // left Call
        if(root->left) root->left = addOneRow(root->left , val , depth);
        if(root->right) root->right = addOneRow(root->right , val , depth);

        cnt--;          // bactracking when we return we need to decrement our level.

        return root;
    }
};

/*
T.C = O(N) , S.C = O(H)

-> So we have to add the give value at given depth. so here we have used Recursive.
-> Once we reached at our target we need to store the Leftsubtree and Rightsubtree. after that we make a node of Given Val. and attached to the curr. left subtree and attached the Original's Subtree to the Left of the Made new Node.
-> Same above step for Right Part of Tree.
-> return root.

Edge case : depth = 1 and we need to add val node at depth - 1 position. (Which is written on 1st IF condition)

*/
