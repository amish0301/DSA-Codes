class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freqMp;

        // store the freq
        for(char ch : s) freqMp[ch]++;

        map<int,string> mp;
      
        for(auto it: freqMp) {

            int lenOfFreqChar = it.second;
            char c = it.first;

            mp[lenOfFreqChar] += string(lenOfFreqChar , c);
        }


        string ans;
        for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
            ans += it->second;
        }
        
        return ans;
        
    }
};


// #LeetCode Medium Way
// T.C = O(N) , S.C = O(N)
