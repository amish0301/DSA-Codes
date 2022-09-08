
  /*   T.C = O(N) : S.C = O(H)   */

void dfs(Node* &root , int &k , int &i, int &sum) {
    if(root == NULL) return ;
    
    dfs(root->left , k , i , sum);
    if(i < k) {
        sum += root->data;
        i++;
    }
    
    if(i < k) {
        dfs(root->right,k,i,sum);
    }
}

int sum(Node* root, int k) 
{ 
    int sum = 0 , i = 0;
    dfs(root,k,i,sum);
    return sum;
}

// We know that an inorder of BST is Sorted so we can easily find the kth Smallest sum of Values so that's why we used the Inorder Traversal
