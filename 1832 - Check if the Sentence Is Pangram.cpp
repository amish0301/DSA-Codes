class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        int f[26] = {0};

        for(int i = 0; i < n; i++) {
            f[sentence[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) if(f[i] < 1) return false;

        return true;
    }
};

// T.C = O(N) , S.C = O(26)
// Level : Easy
