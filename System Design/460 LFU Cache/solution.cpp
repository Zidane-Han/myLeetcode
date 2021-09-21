struct cachenode {
    int key;
    int value;
    int freq;
    list<int>::iterator itt;
};

class LFUCache {
private:
    const int cap;
    int min_freq = 0;
    
    unordered_map<int, cachenode> keytab;   // (key, node) pair
    unordered_map<int, list<int>> freqtab;  // (freq, list of nodes) pair

    void UpdateFreq(cachenode& node) {
        int frq = ++(node.freq);
        freqtab[frq-1].erase(node.itt);
        if (freqtab[frq-1].empty() && min_freq == frq -1) {
            freqtab.erase(frq-1);
            min_freq++;
        }
        
        freqtab[frq].push_front(node.key);
        node.itt = freqtab[frq].begin();
        
        return;
    }
    
    
public:
    LFUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        auto it = keytab.find(key);
        if (it == keytab.end()) {
            return -1;
        }
        
        // update it freq & move it in freqtab
        UpdateFreq(it->second);
        
        return it->second.value;
        
    }
    
    void put(int key, int value) {
        if (cap == 0)   return;
        
        auto it = keytab.find(key);
        // already exist
        if (it != keytab.end()) {
            it->second.value = value;
            UpdateFreq(it->second);
            return;
        }
        
        // not exist
        if (keytab.size() == cap) {
            int key_del = freqtab[min_freq].back();
            freqtab[min_freq].pop_back();
            
            keytab.erase(key_del);
        }
        min_freq = 1;
        
        // add into tabs
        freqtab[min_freq].push_front(key);
        keytab[key] = {key, value, min_freq, freqtab[min_freq].begin()};
        
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */