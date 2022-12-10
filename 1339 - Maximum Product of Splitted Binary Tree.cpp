class Solution {
public:
    int totalSumofTree(TreeNode* root) {

        if(!root) return 0;
        return (root->val + totalSumofTree(root->left) + totalSumofTree(root->right));

    }

    long int dfs(TreeNode* root , int sum , long int& ans) {
        
        // base case
        if(!root) return 0;

        long int subtree_sum = 0;
        subtree_sum += dfs(root->left , sum , ans) + dfs(root->right , sum , ans) + root->val; 

        // finding max product
        ans = max(ans , (subtree_sum * (sum - subtree_sum)));

        return subtree_sum;
    }   

    int maxProduct(TreeNode* root) {

        // calculating total sum
        int total_sum = totalSumofTree(root);
        long int ans = 0;

        dfs(root , total_sum , ans);
        return ans % (1000000007);
    }
};


// #LeetCode Medium Way
// T.C = O(N) , S.C = O(H) [Recursive Stack space]

/*

Q. : in this Q. we need to maximize the product of Sum of splitted BT.

Step 1 : first Find the total_sum of Binary tree so that when we need the summation of other part of subtree so we just deduct the curr_sum of tree from total_sum.
Step 2 : now find the subtree_sum by going to each node recursively and update the maxProduct using this Formula : (total_sum - subtree_sum) * subtree_sum  [where subtree_sum = current node of subtree sum]
Step 3 : return the ans.

#peaceOut :)

*/
