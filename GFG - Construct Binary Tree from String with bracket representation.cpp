class Solution{
public:

    Node* dfs(int &idx , string &s) {
        
        // base case
        if(idx == s.length() || s[idx] == ')') {
            idx++;
            return NULL;
        }
      
        // first fetch the root Node
        int num = 0;
        while(idx < s.length() && isdigit(s[idx])) {
            num = (num * 10) + s[idx] - '0';
            idx++;
        }
        
        // if we reach here means we have to make a root node
        Node* root = new Node(num);
        
        // make left Subtree
        if(idx < s.length() && s[idx] == '(') {
            idx++;
            root->left = dfs(idx,s);
        }
        
        // make right subtree
        if(idx < s.length() && s[idx] == '(') {
            idx++;
            root->right = dfs(idx,s);
        }
        idx++;
        
        return root;
    }
    
    // function to construct tree from string
    Node *treeFromString(string str){
        int idx = 0;
        return dfs(idx,str);
    }
};

// #GFG Medium way
// T.C = O(N) , Auxilliary Space : O(N)
// #NeverGiveUp

// Concept : DFS + String
