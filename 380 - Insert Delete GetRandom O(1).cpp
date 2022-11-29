class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        // if value is found
        if(mp.find(val) != mp.end()) return false;

        v.emplace_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {

        // if value is not present
        if(mp.find(val) == mp.end()) return false;

        // main logic to understand 
        //we're trying to change the position of the ele. which we want to delete and take that ele. at last index of array bcoz we don't have praticular idx
      
        int last = v.back();
        mp[last] = mp[val];
        v[mp[val]] = last;

        v.pop_back();              
        mp.erase(val);
        return true;
    }
    
    int getRandom() {

        // returning random value
        return v[rand() % v.size()];
    }

    private:
    unordered_map<int,int> mp;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */  

/* 

#LeetCode Medium way
T.C = O(1) [in best case] or O(N)
S.C = O(N) -> creating Vector + O(N) -> creating map == O(N)

*/
