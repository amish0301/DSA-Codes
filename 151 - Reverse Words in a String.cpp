class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        stringstream str(s);
        string word;

        while(str >> word) v.push_back(word);   // store the seprate word

        reverse(v.begin() , v.end());
        string ans;

        for(const auto &it : v) ans += " " + it;    
        ans.erase(0,1);

        return ans;
    }
};
