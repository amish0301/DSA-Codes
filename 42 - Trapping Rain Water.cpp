class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
// Better Solution: T.C = O(N) , S.C = O(N)
//         vector<int> left(n,0) , right(n,0);
        
//         // find left max for every index
//         for(int i = 1; i < n; i++) left[i] = max(left[i-1] , height[i-1]);
//         for(int i = n-2; i >= 0; i--) right[i] = max(right[i+1] , height[i+1]);
//         for(int i = 1; i < n; i++) ans += max(0,min(left[i] , right[i]) - height[i]);
//         return ans;
      
      
     
// 2 Pointer Approach (Optimal) : T.C = O(N) , S.C = O(1)
        int l = 0 , r = n - 1;
        int leftMax = 0 , rightMax = 0;
        
        while(l <= r) {
            
            // check if left is lesser than right
            if(height[l] <= height[r]) {
                
                // update the leftMax value
                if(height[l] >= leftMax) leftMax = height[l];
                else ans += leftMax - height[l];
                
                l++;
            }
            
            else {
                
                // update the rightMax value
                if(height[r] >= rightMax) rightMax = height[r];
                else ans += rightMax - height[r];
                
                r--;
            }
        }
        
        return ans;
    }
};
