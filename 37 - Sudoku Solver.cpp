class Solution {

bool isSafe(int row , int col , vector<vector<char>>& board, char val) {
        // check for row and col
        for(int i = 0; i < 9; i++) {

            // checking for row
            if(board[row][i] == val) return false;

            // checking for column
            if(board[i][col] == val) return false;

            // checking for 3*3 submatrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
        }

        return true;
}

bool helper(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char val = '1'; val <= '9'; val++) {
                        if(isSafe(i,j,board,val)) {
                            board[i][j] = val;

                            if(helper(board) == true) return true;  // check for further call
                            else board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};

// #LeetCode Hard Way
// Consept : Backtracking

// T.C = O(n^2) , S.C = O(n^2) [Recursive Call stack]
