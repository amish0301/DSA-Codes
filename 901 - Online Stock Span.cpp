class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx = 0;
    StockSpanner() {}
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && st.top().first <= price) {
            ans += st.top().second;
            st.pop();
        } 
        st.push({price,ans});
        return ans;  
    }
};

// T.C = O(N) , S.C = O(N)
// #LeetCode Medium Way

// here we have taken a stack bcoz we need to maintain the track of prevoius numbers so if top ele of stack is <= curr. ele then ans++ and poped that ele
