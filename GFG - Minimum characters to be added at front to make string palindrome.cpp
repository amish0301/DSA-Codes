// GFG HARD:

//Approach 1 : Brute Force : T.C = O(N^2)
// here we just keep jth ptr at last and we are checking that if at any moment we didn't found the palindrome then we will increased the count of the char. and then move towards the left side.

private:
bool checkPalindrome(string &s , int j) {
    
        int i = 0;
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        
    return true;
}
public:
    int minChar(string s){
        int end = s.length() - 1;
        int cnt = 0;

        while(end >= 0) {
            if(checkPalindrome(s,end))
                return s.length() - 1 - end;
            
            end--;
        }
        return -1;
    }
};


// Approach 2 : Optimal : T.C = O(N)
class Solution {
public:
    int minChar(string s){
        
        int l = 0, h = s.length() - 1 , add = 0;
        while(l < h) {

        // if both are same no need to do anything
        if(s[l] == s[h]) {
            l++;
            h--;
        }
        else {
            add = s.length() - h;   // we are storing that value which is temporary right now
            l = 0;

            while(s[l] == s[h]) {
                add--;
                l++;
            }
            h--;
         }
     }
       return add;
   }
};
