// ***************** Not too Much Optimised - My Submitted Sol. *********************
// T.C = O(nlogn) , S.C = O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        int n = nums.size() , sum = 0 , repeatedEle = 0;
        int idealSum = n*(n+1)/2;

        sort(nums.begin(),nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) repeatedEle = nums[i];
            sum += nums[i];
        }

        sum += nums[0];
        return {repeatedEle , idealSum-sum};
    }
};

// ************* Optimised - Discussion Sol. *******************
// T.C = O(n) , S.C = O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != nums[nums[i] - 1]) swap(nums[i] , nums[nums[i] - 1]);
        }

        int i = 0;
        for(; i < nums.size(); i++)
            if(nums[i] != i + 1) break;
        
        return {nums[i] , i+1};
    }
};

// #Leetcode Easy Problem
