class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> uniqueValues;
        map<int,int> mp;
        int n = matches.size();

        for(int i = 0; i < n; i++) {

            // insert the values of matches vector in set for uniqueness in further calculation
            uniqueValues.insert(matches[i][0]);
            uniqueValues.insert(matches[i][1]);

            // store which player lose the match nd how many times
            mp[matches[i][1]]++;
        }

        vector<vector<int>> ans(2);

        // iterating over set
        for(auto i = uniqueValues.begin(); i != uniqueValues.end(); i++) {

            // if value is not find in map it means that player is not lose any match
            if(!mp.count(*i))       ans[0].push_back(*i);
            else if(mp[*i] == 1)    ans[1].push_back(*i); 
        }

        sort(ans[0].begin() , ans[0].end());
        sort(ans[1].begin() , ans[1].end());

        return ans;
    } 
};

/* 

#LeetCode Medium way

T.C = O(N)

Distribution of S.C = O(N) -> for Creating Set + O(N) -> for creating Map + O(2) -> for creating ans vector

S.C = O(N)

*/
