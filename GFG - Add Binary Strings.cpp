class Solution{
public:	
    string addBinary(string a, string b)
	{
	    int i = a.length() - 1 , j = b.length() - 1;
	    int carry = 0;
	    string ans = "";
	    
	    while(i >= 0 || j >= 0) {
	        
	        // if anythig is not mention then consider there '0'
	        int sum = ( (i >= 0 ? a[i] : '0') - '0') + ( (j >= 0 ? b[j] : '0') - '0') + carry;
	        carry = sum / 2;
	        ans.push_back((sum%2) + '0');
	        
	        i--;
	        j--;
	    }
	    
	    // if carry is still there then we have to add into our ans
	    if(carry == 1) ans.push_back(carry + '0');
	    reverse(ans.begin() , ans.end());   // we need to reverse the ans because we are doing push_back operation on string 
	    
	    int idx = 0;
	    while(idx < ans.length() && ans[idx] != '1') idx++;    
	    
	    
	    return ans.substr(idx,ans.length());
	}
};

// T.C = O(max (len(a) , len(b)) ) + O(N) -> [for reversing the String]
// S.C = O(max (len(a) , len(b)) )

// #NeverLoseHope && #NeverGiveUp
