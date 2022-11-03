class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin() , arr.end());
        
        int maxWindow = INT_MIN , n = arr.size();
        int i = 0 , j = 0;
        
        while(j < n) {
            if(arr[j] - arr[i] <= k) j++;
            else if(i < j) i++;
            
            maxWindow = max(maxWindow , j - i);
        }
        
        return n - maxWindow;
    }
};

// #GFG Medium Way
// T.C = O(nlogn) , S.C = O(1)
// Concept Used - Sliding Window 

// Idea is that if we found the max sz of window in which diff. is <= k then we can just remove the ele. apart from that window means n-window sz.
