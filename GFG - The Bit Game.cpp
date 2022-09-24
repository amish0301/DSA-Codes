class Solution{   
public:
    int swapBitGame(long long n){
        int cnt = 0;
        
        while(n > 0) {
            cnt++;
            n = n & (n - 1);
        }
        
        if(cnt & 1) return 1;
        
        return 2;
    }
};

/*  Question Summary:

Two players, Player 1 and Player 2, are given an integer N to play a game. The rules of the game are as follows :
1. In one turn, a player can remove any set bit of N in its binary representation to make a new N.
2. Player 1 always takes first turn.
3. If a player cannot make a move, he loses.

T.C = O(logN) , S.C = O(1)

Approach: 
-> so here in 1st rule we can see that we have to Remove SetBit(1) so we know how to reduce the set bit and hence as we know by removing set bit Number will decreased.
-> and we checked how much set bit is there if its Even then 2nd Will Win and else 1st will win.

*/
