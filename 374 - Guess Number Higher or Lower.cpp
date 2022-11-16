class Solution {
public:
    int guessNumber(int n) {

        int low = 1 , high = n;

        while(low <= high) {

            int mid = low + ( (high-low) >> 1);
            int m = guess(mid);

            if(m == 0) return mid;
            else if(m == -1) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

// T.C = O(logN) , S.C = O(1)
// #LeetCode easy Way
