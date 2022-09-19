class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> ans(n,0);
        stack<int> st;
        st.push(a[0]);
        ans[0] = -1;
        
        for(int i = 1; i < n; i++) {
            while(!st.empty() && st.top() >= a[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(a[i]);
        }
        return ans;
    }
};

// T.C = O(n) , S.C = O(n)

// Here we need to find the neearest element so we will be using stack for maintain the nearest Smallest ele. 
// in the Top of Stack there will be always Smallest ele. is Present.
