class Solution {
private:
    inline bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        int i = 0 , j = s.length() - 1;

        while(i < j) {
            if(!isVowel(s[i])) i++;
            else if(!isVowel(s[j])) j--;
            else {
                swap(s[i++],s[j--]);
            }
        }
        return s;
    }
};

// #LeetCode Easy Way
// T.C = O(N/2) ~ O(N) , S.C = O(1)
