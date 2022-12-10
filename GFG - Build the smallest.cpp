
// for removing the leading zeros from string
string leadingZeros(string& s) {
    
    int i = 0;
    while(s[i] == '0') i++;
    
    s.erase(0, i);
    
    return s;
}



string buildLowestNumber(string num, int k)
{
    stack<char> st;
    
    for(int i = 0; i < num.length(); i++) {
        
        char ch = num[i];
        
        while(!st.empty() && st.top() > ch && k > 0) {
            st.pop();
            k--;
        }
        
        st.push(ch);
    }
  
// Edge Case for k value remaining :
  
    // what if we still have k digit to remove
    while(!st.empty() && k > 0) {
        st.pop();
        k--;
    }
    
    string ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin() , ans.end());

// Edge Case for Leading Zero String :

    if(ans[0] == '0')
        ans = leadingZeros(ans);
        
    if(ans.length() == 0) return "0";
    return ans;
}

// #GFG Medium Way
// T.C = O(N) , S.C = O(N)      :: where N = len. of String
