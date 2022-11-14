class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // base case
        if(!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode == NULL) ans.append("#,");
            else ans.append(to_string(currNode->val) + ',');

            if(currNode != NULL) {
                q.push(currNode->left);
                q.push(currNode->right);
            }

        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;

        string str;
        stringstream s(data);   // useful to iterate over the objective of str

        getline(s,str,',');     // to fetch the particular part of string
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#") node->left = NULL;
            else {
                TreeNode* nodeLeft = new TreeNode(stoi(str));
                node->left = nodeLeft;
                q.push(nodeLeft);
            }

            getline(s,str,',');
            if(str == "#") node->right = NULL;
            else {
                TreeNode* nodeRight = new TreeNode(stoi(str));
                node->right = nodeRight;
                q.push(nodeRight);
            }
        }
        return root;
    }
};

// #LeetCode HARD Way
// T.C = O(N) , S.C = O(N)


// this q. shows that How input/output of Every Tree Q. is Made in Backend for Leetcode
