class Solution{
    public:
  
    bool check(vector<ll> a, vector<ll> b, int n) {
        sort(begin(a) , end(a));
        sort(begin(b), end(b));
        
        for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
        return true;
    }
};
