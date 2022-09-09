class Solution {
private:
    static bool comp(vector<int> &a , vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
  
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin() , properties.end() , comp);
        int ans = 0 , maxTillNow = INT_MIN , n = properties.size();
        
        for(int i = n - 1 ; i >= 0; i--) {
            
            if(properties[i][1] < maxTillNow) ans++;
            
            maxTillNow = max(maxTillNow , properties[i][1]);  
        }
        return ans;
    }
};
