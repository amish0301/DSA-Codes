class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0 , j = tokens.size() - 1;
        int score = 0 , maxScore = 0;
        
        sort(tokens.begin() , tokens.end());
        while(i <= j) {
            
     // if power is more than curr value then we increment the score and reduce the power
            if(power >= tokens[i]) {
                power -= tokens[i++];
                score++;
            }
            else {
   // check if score at least 1 then we grab the Max power and and score is reduce
                if(score >= 1) {
                    power += tokens[j--];
                    score--;
                }
                else i++;   // if we don't have the least score then we just move ahead
            }
            
            maxScore = max(maxScore,score); 
        }
        return maxScore;
    }
};

// T.C = O(N) -> in worst case
// S.C = O(1)
