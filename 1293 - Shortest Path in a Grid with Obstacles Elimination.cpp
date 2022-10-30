class Solution {
private:
    int helper(vector<vector<int>> &mat , int k) 
    {
        int m = mat.size() , n = mat[0].size();

        vector<vector<int>> vis(m , vector<int>(n , -1));
        queue<vector<int>> q;  // q stores -> rowIdx , colIdx , curr. path , remaining obstacles
        q.push({0,0,0,k});

        while(!q.empty()) {

        auto t = q.front();
        q.pop();
        int i = t[0] , j = t[1];

        // if idx is out of bound
        if(i < 0 || j < 0 || i >= m || j >= n) continue;

        if(mat[i][j] == 1) {
            if(t[3] > 0) t[3]--;
            else continue;
        }

        if((i == m - 1) && (j == n - 1)) return t[2];

        if(vis[i][j] != -1 && vis[i][j] >= t[3]) continue;
        vis[i][j] = t[3];

        // if we reached over here it means we are good to go
        q.push({i+1,j,t[2] + 1 , t[3]});
        q.push({i-1,j,t[2] + 1 , t[3]});
        q.push({i,j+1,t[2] + 1 , t[3]});
        q.push({i,j-1,t[2] + 1 , t[3]});
    }
    return -1;        
}
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        return helper(grid,k);
    }
};

// T.C = S.C = O(M*N) : M = grid.size() , N = grid[0].size()
// #LeetCode Hard
// BFS Approach
