class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> currency = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        for(int i = 9; i>= 0; i--) {
            while(N >= currency[i]) {
                ans.push_back(currency[i]);
                N -= currency[i];
            }
        }
        return ans;
    }
};

// #GFG Medium
// T.C = O(N) , S.C = O(N)
