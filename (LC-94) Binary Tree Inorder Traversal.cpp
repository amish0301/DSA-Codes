
/*   RECURSIVE METHOD T.C = O(N) : S.C = O(H)  */

void inorder(TreeNode* root , vector<int> &ans)
    {
        if(!root) return ;
        
        inorder(root->left , ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        inorder(root,v);
        return v;
}


/*   ITERATIVE METHOD  T.C = O(N) : S.C = O(N)   */


 vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while(1)
        {
            if(node != NULL)
            {
                s.push(node);
                node = node -> left;
            }
            else {
                if(s.empty()) break;
                
                node = s.top();
                s.pop();
                
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
