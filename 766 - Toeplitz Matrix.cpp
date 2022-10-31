class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m-1; i++) {
            int r = i , c = 0 , val = -1;
            while(r < m && c < n) {
                if(val == -1)
                    val = matrix[r][c];

                else if(val != matrix[r][c]) return false;
                r++;
                c++;
            }
        }
      
// Second Half Of Matrix:
        for(int i = 1; i < n-1; i++) {
            int r = 0 , c = i , val = -1;
            while(r < m && c < n) {
                if(val == -1)
                    val = matrix[r][c];

                else if(val != matrix[r][c]) return false;
                r++;
                c++;
            }
        }

        return true;
    }
};

// #Leetcode Easy Way
// T.C = 2 * O(m*n) , S.C = O(1)
// Upper Sol. is mine but in terms of T.C it beats only 18.33% and S.C beats 98.97%



// This is Observation based or Illiustrative Approach:
// T.C = O(m*n) , S.C = O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }

        return true;
    }
};
