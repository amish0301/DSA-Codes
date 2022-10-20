class Solution {
public:
    string intToRoman(int num) {
        
    int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12 , d;
    string ans="";
      
    while(num>0)
    {
        d = num/number[i];
        num = num%number[i];

        while(d--) ans += sym[i];

        i--;
    }

        return ans; 
    }
};

// A very Good Q. : Level : Medium
// T.C = O(N) , S.C = O(1)
