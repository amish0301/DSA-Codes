class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26,0) , w2(26,0);
        vector<int> charCheck1(26,0) , charCheck2(26,0);

        for(char c: word1) {
            w1[c-'a']++;
            charCheck1[c-'a'] = 1;
        }

        for(char c: word2) {
            w2[c-'a']++;
            charCheck2[c-'a'] = 1;
        }

        sort(w1.begin() , w1.end());
        sort(w2.begin() , w2.end());
        
        return w1 == w2 && charCheck1 == charCheck2;
    }
};

// #LeetCode Medium Way
// T.C = O(N) , S.C = O(26)

// we have to check that can str1 convert into the str2 or Not? so we just checked that is Freq. is same in both the string or not and we just checked that every element is present in str1 is present in str2 or not. if both condition are true then it's true otherwise it's false
