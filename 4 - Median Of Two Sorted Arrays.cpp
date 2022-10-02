class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
        // we consider the 1st array as a Smaller over here
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);

        // now we have to partition the array
        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0 , high = n1;    //try to do the Binary search on Smaller array
        
        while(low <= high) {

            // make it 1st partition
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // left part of 1st and 2nd array
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1 ];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            // right part of both arrays
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            // if parts are satisfied then check it's len. of array is even or odd
            if(l1 <= r2 && l2 <= r1) {
              
                if((n1 + n2) % 2 == 0) {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
                else return max(l1,l2);
              
            }
            else if(l1 > l2) high = cut1 - 1;

            else low = cut1 + 1;
        }
        return 0.0;
    }
};
