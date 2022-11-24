class Solution {
public:
    bool helper(int i , int j , vector<vector<char>> &mat, string word) {

        if(!word.size()) return true;

        if(i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || mat[i][j] != word[0]) return false;
        
        
        char ch = mat[i][j];
        mat[i][j] = '.';
        string str = word.substr(1);
        
        bool checkFurther = (helper(i-1,j,mat,str) || helper(i+1,j,mat,str) || helper(i,j-1,mat,str) || helper(i,j+1,mat,str));

        mat[i][j] = ch;
        return checkFurther;

    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(helper(i,j,board,word))
                    return true;

        return false;
    }
};

// #LeetCode Medium Way
// Concept - DFS + Backtracking + string

// T.C = O(N^2) , Auxilliary S.C = O(row + length(word)); 

// HINT why we've to use Backtracking : in Backtracking concept there are Multiple Ways(Path) to reach out to ans. and Only 1 ans. is Exist.
