void findAll() {
    //code here
    
    set<int> st;
    for(int i = 1; i <= 3; i++) st.insert(i);
    
    int n = 1000000;
    for(int i = 1; i <= n; i++) {
        
        int num = i;
        bool f = true;
        
        while(num > 0) {
            int digit = num % 10;
            if(st.find(digit) == st.end()) {
                f = false;
                break;
            }
            num /= 10;
        }
        
        if(f) mp[i] = 1;
    }
}
