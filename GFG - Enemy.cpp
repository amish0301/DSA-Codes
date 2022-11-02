class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            vector<int> rows;
            int maxRow = 0;
            
            rows.push_back(-1);
            for(vector<int> v : enemy) {
                rows.push_back(v[0] - 1);       // making 0-based index
            }
            rows.push_back(n);
            sort(rows.begin() , rows.end());
            
            for(int i = 1; i < rows.size(); i++) {
                int prev = rows[i-1];
                int curr = rows[i];
                
                maxRow = max(maxRow,(curr-prev)-1);
            }
            
// Same Procedure for Col Below:
          
            vector<int> cols;
            int maxCol = 0;
            
            cols.push_back(-1);
            for(vector<int> v : enemy) {
                cols.push_back(v[1] - 1);       // making 0-based index
            }
            cols.push_back(m);
            sort(cols.begin() , cols.end());
            
            for(int i = 1; i < cols.size(); i++) {
                int prev = cols[i-1];
                int curr = cols[i];
                
                maxCol = max(maxCol,(curr-prev)-1);
            }
            
            return maxRow * maxCol;
        }
};

// T.C = S.C = O(m+n) ~ O(N)
// Idea behind this sol. is, we just find the diff. from start edge of mat. to enemy present and enemy to col edge of diff. and do it for row and col.
