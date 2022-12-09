bool isValid(int x , int y , int row , int col) {
    return (x >=0 && x < row) && (y >= 0 && y < col);
}


long long numOfWays(int N, int M)
{
    long mod = 1e9 + 7;
    
    // dir for diff. idxs
    int dirX[] = {-2,-2,-1,1,2,2,-1,1};    
    int dirY[] = {-1,1,2,2,-1,1,-2,-2};
    
    long long ans = 0;
    
    // traverse the ChesseBoard
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            
            long totalPossiblePos = N * M;
            long totalPosToMinus = 1L;       // it's self position is also invalid to place other knight
            
            // check whether which position we need to remove by traversing all the possible idxs
            for(int idx = 0; idx < 8; idx++) 
                if(isValid(i+dirX[idx] , j+dirY[idx] , N , M)) totalPosToMinus++; 
            
            totalPossiblePos -= totalPosToMinus;
            ans += (totalPossiblePos) % mod;
        }
    }
    
    return ans%mod;
}

// #GFG Medium Way
// T.C = O(N*M) , S.C = O(1)

// it's very good prblm and it's intuitive as well bcoz we just need to tell that where we cannot place the knight such that other knight can not be attack each other.
