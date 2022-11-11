class Solution {
private:
    bool isPrime(int n) {
        
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0) return false;
            
        return true;
    }
  
public:
    string isSumOfTwo(int N){
        
        for(int i = 2; i <= N/2; i++)
            if(isPrime(i) && isPrime(N-i)) return "Yes";
        
        return "No";
    }
};

// #GFG Easy Way
// T.C = O(N*sqrt(N)) , S.C = O(1)

// we know x+y = N (x = y = prime) so we iterate firt N/2 terms and our (x = ith term) and (y = N - x) so we check that if y is Prime or not.
// if both are prime means we got our ans. otherwise check further
