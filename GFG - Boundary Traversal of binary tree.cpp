class Solution {
public:

    void leftBoundry(Node* root , vector<int> &left) {
        
        // base case
        if(root == NULL || (root->left == NULL and root->right == NULL) ) return ;
        
        left.push_back(root->data);
        
        if(root->left) leftBoundry(root->left, left);
        else leftBoundry(root->right , left);
        
    }
    
  
    void leafs(Node* root , vector<int> &leaf) {
        
        if(root == NULL) return ;
        
        if(root->left == NULL and root->right == NULL) {
            
            leaf.push_back(root->data);
            return ;
        }
        
        leafs(root->left , leaf);
        leafs(root->right , leaf);
    } 
  
  
    void rightBoundry(Node* root , vector<int> &right) {
        
        // base case
        if(root == NULL || (root->left == NULL and root->right == NULL) ) return ;
        
        right.push_back(root->data);
        
        if(root->right != NULL) rightBoundry(root->right, right);
        else rightBoundry(root->left , right);
        
    }
  
  
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // inset root
        ans.push_back(root->data);
        
        
        // step 1 : left Boundry
        vector<int> left;
      
        leftBoundry(root->left , left);
      
        for(int i = 0; i < left.size(); i++) ans.push_back(left[i]);
        
        
        // step 2 : leaf nodes
        vector<int> leaf;
        
        leafs(root->left , leaf);
        leafs(root->right , leaf);
        
        for(int i = 0; i < leaf.size(); i++) ans.push_back(leaf[i]);
        
        
        // step 3 : right Boundry
        vector<int> right;
      
        rightBoundry(root->right , right);
      
        reverse(right.begin() , right.end());
        for(int i = 0; i < right.size(); i++) ans.push_back(right[i]);
        
        
        return ans;
    }
};

// T.C = O(N) , S.C = O(N)
// #GFG Medium Way

// Concept : Trees Traversal
