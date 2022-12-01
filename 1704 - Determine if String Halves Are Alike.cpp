class Solution {
public:
    bool halvesAreAlike(string s) {

        int cntVowel_FirstHalve = 0 , cntVowel_SecondHalve = 0;
        int i = 0 , j = s.length() - 1;

        while(i < (s.length() >> 1)) {
          
            if(s[i] == 'a' || s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'|| 
               s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U') 
               cntVowel_FirstHalve++;

            if(s[j] == 'a' || s[j] == 'e'|| s[j] == 'i'|| s[j] == 'o'|| s[j] == 'u'|| 
               s[j] == 'A'|| s[j] == 'E'|| s[j] == 'I'|| s[j] == 'O'|| s[j] == 'U') 
               cntVowel_SecondHalve++;

            i++;
            j--;
        }

        return cntVowel_FirstHalve == cntVowel_SecondHalve;
    }
};

// #LeetCode Easy way
// T.C = O(N >> 1) == O(N)
// S.C = O(1)

// #Simpool
