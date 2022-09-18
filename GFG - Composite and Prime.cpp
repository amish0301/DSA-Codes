class Solution {
	public:
		int Count(int l, int r){
		    int prime = 0 , comp = 0;
		    
		    vector<bool> isPrime(r+1,true);     // intially marked all the values are Prime
		    isPrime[0] = isPrime[1] = false;
		    
		    for(int i = 2; i <= r; i++) {
		        if(isPrime[i]) {
		            for(int j = 2*i; j <= r; j += i) isPrime[j] = false;
		        }
		    }
		    
		    for(int i = l; i <= r; i++) {
		        if(isPrime[i]) prime++;
		        else comp++;
		    }
		    // L= 1 then we have already counted so we have to decrease the 1 freq. of composite
		    if(l == 1) comp--;
		    return comp - prime;
		}

};
