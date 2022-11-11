class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;

        for(int right = 1; right < nums.size(); right++) {
            if(nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }
        }

        return left+1;
    }
};

// #LeetCode Easy Way
// T.C = O(N) , S.C = O(1)

// Here we need to remove the dublicates and find the length of unique char. and we don't want to use extra space
