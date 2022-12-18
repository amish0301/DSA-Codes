class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        int n = t.size();
        stack<int> st;
        vector<int> nge(n,0);

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && t[st.top()] <= t[i]) st.pop();
            if(!st.empty()) nge[i] = st.top() - i;
            st.push(i);

        }

        return nge;
    }
};

// #LeetCode Medium way
// Concept - next Greater element , DS - Stack
// T.C = O(N) , S.C = O(N)
