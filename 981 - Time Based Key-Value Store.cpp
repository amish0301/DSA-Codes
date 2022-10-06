class TimeMap {
public:
    unordered_map<string , unordered_map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // if key found
        if(mp.find(key) == mp.end()) {
            // create map 
            unordered_map<int,string> temp;
            mp[key] = temp;
        }

        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        while(timestamp > 0) {
            if(mp[key].find(timestamp) != mp[key].end()) return mp[key][timestamp];
            timestamp--;
        }
        return "";
    }
};
