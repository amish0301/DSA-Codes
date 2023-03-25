int findElement(int arr[], int n) {
    
    vector<int> maxv(n,0);
    vector<int> minv(n,0);
    int mini = INT_MAX , maxi = INT_MIN;
    
    // finding ith max ele. and store it into vector
    for(int i = 0; i < n; i++) {
        maxi = max(maxi , arr[i]);
        maxv[i] = maxi;
    }
    
    // finding ith min ele. and store it into vector
    for(int i = n-1; i >= 0; i--) {
        mini = min(mini , arr[i]);
        minv[i] = mini;
    }

    
    for(int i = 1; i < n-1; i++) {
        if(arr[i] >= maxv[i] && arr[i] <= minv[i]) return arr[i];
    }
    
    return -1;
}
