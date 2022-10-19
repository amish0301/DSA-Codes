class Solution { 
    public: 
    string countAndSay(int n , string s = "1") { 
        int i = 0 , j , len = s.length(); 
        string ans = ""; 

        if(n == 1)return s; 

        while(i < len) { 
            j = i; // fixed the starting position where element start to repeating 
            while(i < len && s[i] == s[j])i++; 
            ans += to_string(i-j) + s[j]; 
        } 
        return countAndSay(n-1,ans); 
    } 
};

// T.C = O(N) , S.C = O(N)
// here S.C is O(N) bcoz we are going from 1 to n calls in call-stack
// Level : Medium
