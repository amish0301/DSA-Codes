class Solution {
private:
    void inorder(TreeNode* &root , vector<int> &nums) {
        if(root == NULL) return ;
      
        inorder(root->left , nums);
        nums.push_back(root->val);
        inorder(root->right , nums);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
      
        for(int i = 0 , j = nums.size() - 1; i < j ;) {
            if(nums[i] + nums[j] == k) return true;
            (nums[i] + nums[j] < k) ? i++ : j--;
        }
        return false;
    }
};

// T.C = O(N) , S.C = O(N)
// Level : Easy
