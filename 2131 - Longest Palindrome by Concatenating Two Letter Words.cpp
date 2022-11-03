// Approach 1 : Using Map (T.C = O(N) , S.C = O(N))
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0 , unpair = 0;
        unordered_map<string,int> mp;

        for(string s : words) {
            if(s[0] == s[1]) {
                if(mp[s] > 0) {
                    ans += 4;
                    unpair--;
                    mp[s]--;
                }else{
                    mp[s]++;
                    unpair++;
                }
            }
            else {
                string rev = s;
                reverse(rev.begin() , rev.end());
                if(mp[rev] > 0) {
                    ans += 4;
                    mp[rev]--;
                }
                else{
                    mp[s]++;
                }
            }
        }

        if(unpair > 0) ans += 2;
        return ans;
    }
};


// Approach 2 : Without Map (T.C = O(N) , S.C = O(26*26) ~= O(1))
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      
        vector<vector<int>> cnt(26,vector<int>(26,0));
        int ans = 0;

        for(string s : words) {
            int x = s[0] - 'a' , y = s[1] - 'a';
            if(cnt[y][x]) {
                ans += 4;
                cnt[y][x]--;
            }
            else cnt[x][y]++;
        }

        for(int i = 0; i < 26; i++) {
            if(cnt[i][i] > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};

// #LeetCode Medium Way
