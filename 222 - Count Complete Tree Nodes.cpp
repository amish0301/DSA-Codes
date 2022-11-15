// Using Traversal Approach Iterative 
// T.C = O(N) , S.C = O(N)

class Solution {
private:
    int solve(TreeNode* &root , int cnt) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            cnt += sz;

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;

        if(root == NULL) return cnt;
        return solve(root , cnt);
    }
};

/* ******************************************************************************************************************* */

// Recursive Approach Using Traversal
// T.C = O(N) , S.C = O(H)

class Solution {
private:
    void solve(TreeNode* &root , int cnt) {
        if(root == NULL) return 0;
        
        cnt++;
        solve(root->left , cnt);
        solve(root->right , cnt);
    }
  
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;

        if(root == NULL) return cnt;
        solve(root , cnt);
      
       return cnt;
    }
};


/* ******************************************************************************************************************* */

// Using Eqaution (Optimised Approach)
// T.C = O(log^2 N) , S.C = O(H)

class Solution {
private:
    int leftH(TreeNode* node) {
        int h = 0;
        while(node) {
            h++;
            node = node->left;
        }

        return h;
    }

    int rightH(TreeNode* node) {
        int h = 0;
        while(node) {
            h++;
            node = node->right;
        }

        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        // find left height and Right height
        int lh = leftH(root);
        int rh = rightH(root);

        if(lh == rh) return (1<<lh) - 1;      // if left and right are same it means tree is balanced and complete BT so we did 2^h - 1 nodes are present

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


//  #Leetcode Medium Way
