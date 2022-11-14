class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        
        vector<bool> vis(S.length() , false);   // to ensure that we'll not use the char. which is already used
        int ans = 0;
        
        for(int i = 0; i < S.length(); i++) {
            
            int widx = 0;
            
            if(S[i] == W[widx] && !vis[i]) {
                
                vis[i] = true;
                widx++;
                int j = i+1;
                
                while(j < S.length() && widx < W.length()) {
                    
                    if(S[j] == W[widx] && !vis[j]) {
                        vis[j] = true;
                        widx++;
                    }
                        
                    j++;
                }
                
                if(widx == W.length()) ans++;
            }
        }
        
        return ans;
    }
};

// #GFG Medium Way
// T.C = O(N^2) , S.C = O(N)
