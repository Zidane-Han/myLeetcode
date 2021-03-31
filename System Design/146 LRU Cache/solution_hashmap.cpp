class LRUCache {
private:
    int cap;
    list<pair<int, int>> used;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = dict.find(key);
        if (it == dict.end())   return -1;
        used.splice(used.begin(), used, it->second);  // move the ele from used into the front of used
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = dict.find(key);
        if (it != dict.end())   used.erase(it->second);
        used.push_front(make_pair(key, value));
        dict[key] = used.begin();
        
        if (used.size() > cap) {
            int tmp = used.back().first;
            used.pop_back();
            dict.erase(tmp);
        }
     
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */