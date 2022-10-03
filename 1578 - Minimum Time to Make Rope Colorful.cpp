class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0 , totalCost = 0 , maxCost = 0 , n = s.length();

        // here untill there is a Same char. matching we just iterate and finding the total cost
        for(int i = 0; i < n; i++) 
        {
            // check that if any consecutive char. is Not matching then make all cost to 0
            if(i > 0 && s[i] != s[i-1]) {
                ans += totalCost - maxCost;
                totalCost = maxCost = 0;
            }

            totalCost += cost[i];
            maxCost = max(maxCost , cost[i]);
        }
        ans += totalCost - maxCost;           // for last iteration
        return ans;
    }
};

// T.C = O(N) , S.C = O(1)
