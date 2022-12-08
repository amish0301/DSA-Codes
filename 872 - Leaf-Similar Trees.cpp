
// Brute Force Approach : T.C = O(N) , S.C = O(N)

class Solution {
public:

    void tree1(TreeNode* root , vector<int> &leafNodesOfTree1) {

        if(root == NULL) return ;

        if(root->left == NULL && root->right == NULL) leafNodesOfTree1.push_back(root->val);

        tree1(root->left , leafNodesOfTree1);
        tree1(root->right , leafNodesOfTree1);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leafNodesofTree1;
        tree1(root1 , leafNodesofTree1);

        vector<int> leafNodesofTree2;
        tree1(root2 , leafNodesofTree2);

        if(leafNodesofTree1.size() == leafNodesofTree2.size()) {

            for(int i = 0; i < leafNodesofTree1.size(); i++)
                if(leafNodesofTree1[i] != leafNodesofTree2[i]) return false;
                
        }else return false;

        return true;
    }
};



// Optimal Approach : T.C = O(N) , S.C = O(H)

class Solution {
public:

    int dfs(stack<TreeNode*> &st) {

            while(true) {
                TreeNode* root =  st.top(); st.pop();

                if(root->left) st.push(root->left);
                if(root->right) st.push(root->right);

                if(!root->left && !root->right) return root->val;
            }
            
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        stack<TreeNode*> s1 , s2;
        s1.push(root1); s2.push(root2);

        while(!s1.empty() && !s2.empty())
            if(dfs(s1) != dfs(s2)) return false;

        return s1.empty() && s2.empty();
    }
};



// #LeetCode Easy Way
// it's very simple that we just need to check that either both Trees are Sequential or not
