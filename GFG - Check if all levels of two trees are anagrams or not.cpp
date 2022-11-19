class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*> q1;
        queue<Node*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()) {
            int sz1 = q1.size();
            int sz2 = q2.size();
            
            if(sz1 != sz2) return false;
            
            unordered_map<int,int> mp;
            
            for(int i = 0; i < sz1; i++) {
                Node* node1 = q1.front();
                Node* node2 = q2.front();
                
                q1.pop();
                q2.pop();
                
                mp[node1->data]++;
                mp[node2->data]--;
                
                if(node1->left != NULL) q1.push(node1->left);
                if(node1->right != NULL) q1.push(node1->right);
                
                if(node2->left != NULL) q2.push(node2->left);
                if(node2->right != NULL) q2.push(node2->right);
            }
            
            for(auto i:mp)
                if(i.second != 0) return false;
        }
        
        return true;
    }
};

// #GFG Hard Way(Not seems)
// T.C = O(NlogN) , S.C = O(N)

// Note: IF you know about what is anagram then this Q. is cup of tea
