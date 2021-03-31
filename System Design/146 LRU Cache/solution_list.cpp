class LRUCache {
private:
    int cap;
    vector<int> dict;
    list<int> used;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        dict.resize(3001, -1);
    }
    
    int get(int key) {
        if (dict[key] == -1)    return -1;
        else {
            used.remove(key);
            used.push_back(key);
        }
        return dict[key];
    }
    
    void put(int key, int value) {
        if (dict[key] != -1) {
            dict[key] = value;
            used.remove(key);
            used.push_back(key);
            return;
        }
        
        dict[key] = value;
        if (used.size() == cap) {   // overfilled
            int tmp = used.front();
            used.pop_front();
            dict[tmp] = -1;
        }
        
        used.push_back(key);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */