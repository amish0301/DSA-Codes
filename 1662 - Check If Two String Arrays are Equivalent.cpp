
// Brute Force Approach: T.C = O(N) , S.C = O(N + M) :: [N = Size(word1) , M = Size(word2)]
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "" , s2 = "";

        for(auto str : word1) s1 += str;

        for(auto str : word2) s2 += str;

        if((s1.length() > s2.length()) || (s1.length() < s2.length())) return false;
        else {
            for(int i = 0; i < s1.length(); i++)
                if(s1[i] != s2[i]) return false;
        }
        return true; 
    }
};


// Optimal Approach: T.C = O(N) , S.C = O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
     
        int i = 0 , j = 0;  // str ptr
        int m = 0 , n = 0;  // char. ptr

        while(i < word1.size() && j < word2.size()) 
        {
            if(word1[i][m++] != word2[j][n++]) return false;

            if(m >= word1[i].size()){
                i++;
                m = 0;
            }

            if(n >= word2[j].size()){
                j++;
                n = 0;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};


