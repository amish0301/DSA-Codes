class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        
        // for distinct string we can take set
        set<string> st;
        for(int i = 0; i < n; i++) st.insert(contact[i]);
        string prefixStr = "";
        
        for(int i = 0; i < s.length(); i++) {
            
            prefixStr += s[i];
            vector<string> v;
            
            for(string str : st) {
                if(i >= str.length()) continue;
                if(prefixStr == str.substr(0,i+1)) v.push_back(str);
            }
            
            if(v.size() == 0) v.push_back("0");
            sort(v.begin() , v.end());
            ans.push_back(v);
        }
        
        return ans;
    }
};

// Brute Force also get accepted
// T.C = O(len(s) * size(set) * contact[i]) , S.C = O(contact[i] * len(s)) + O(n)

// Level : Hard
