class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        sort(capacity.begin() , capacity.end());
        
        int mod = 1000000007;
        long long ans = capacity[0];
        
        if(n == 1) return ans;
        
        for(int i = 1 ; i < n; i++) {
            
            capacity[i] -= i;
            ans = (ans * capacity[i]) % mod;
        }
        
        return ans;
    }
};

// #GFG Medium way
// T.C = O(n*logn) , S.C = O(1)

// here we are givem the infinite balls and capacity arr which shows that the capacity of every container. and the condition is every container contain the ATLEAST 1 ball and evry container contain the diff. no of balls (Unique) 

// So what we did first sort the array bcoz we have to fill the ball uniquelly in every container and then we just dcreament the value from every capacity of container
