class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        for(int i = 0;  i < s.length(); i++) {
            if(s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        num = stoi(s);
        return num;
    }
};

// #LeetCode Easy Way
// Auxiallary T.C = O(length of Num) , S.C = O(1)
