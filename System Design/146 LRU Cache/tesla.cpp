
/*
Implement an LRU cache which includes the following features:
  Expire Time - after which an entry in the cache is invalid
  Priority - lower priority entries should be evicted before higher priority entries

The Cache eviction strategy should be as follows:
  Evict expired entries first
  If there are no expired items to evict then evict the lowest priority entries
    Tie breaking among entries with the same priority is done via least recently used.

You can use any language.

Your task is to implement a PriorityExpiryCache cache with a max capacity.  Specifically please fill out the data structures on the PriorityExpiryCache object and implement the entry eviction method.

You do NOT need to implement the get or set methods.

It should support these operations:
  Get: Get the value of the key if the key exists in the cache and is not expired.
  Set: Update or insert the value of the key with a priority value and expiretime.
    Set should never ever allow more items than maxItems to be in the cache.
    When evicting we need to evict the lowest priority item(s) which are least recently used.

Example:
p5 => priority 5
e10 => expires at 10 seconds since epoch

c = NewCache(5)
c.Set("A", value=1, priority=5,  expireTime=100)
c.Set("B", value=2, priority=15, expireTime=3)
c.Set("C", value=3, priority=5,  expireTime=10)
c.Set("D", value=4, priority=1,  expireTime=15)
c.Set("E", value=5, priority=5,  expireTime=150)
c.Get("C")


// Current time = 0
c.SetMaxItems(5)
c.Keys() = ["A", "B", "C", "D", "E"]
// space for 5 keys, all 5 items are included

time.Sleep(5)

// Current time = 5
c.SetMaxItems(4)
c.Keys() = ["A", "C", "D", "E"]
// "B" is removed because it is expired.  e3 < e5

c.SetMaxItems(3)
c.Keys() = ["A", "C", "E"]
// "D" is removed because it the lowest priority
// D's expire time is irrelevant.

c.SetMaxItems(2)
c.Keys() = ["C", "E"]
// "A" is removed because it is least recently used."
// A's expire time is irrelevant.

c.SetMaxItems(1)
c.Keys() = ["C"]
// "E" is removed because C is more recently used (due to the Get("C") event).
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <set>
#include <unordered_map>
#include <string>
#include <list>

using namespace std;

int g_Time = 0;

typedef int CacheData;

struct PriorityExpiryCache {
  int maxItems;
  // TODO(interviewee): implement this
  
  // timeadded & g_time (time gone)  g_time - timeadd > expirytime
  
  unordered_map<string, pair<int, int>> dict; // (key: string; value: time + priority)
  set<pair<int, string>> timepq;  // (expired time, string)
  set<pair<int, string>> prioritypq;  // (priority, string)
  unordered_map<int, list<string> > LRUdict;  // (key: priority; value: items with the same priority ordered by LRU)
  
  // constructor
  PriorityExpiryCache(int m) {
    maxItems = m;
  }
  
  
  /*
  The Cache eviction strategy should be as follows:
  Evict expired entries first
  If there are no expired items to evict then evict the lowest priority entries
    Tie breaking among entries with the same priority is done via least recently used.
  */
    
  void EvictItems() {
    // TODO(interviewee): implement this
    // discard the expired, then low_priority, then LRU elements
    
    // remove expired
    while (true) {
      auto it = timepq.begin();
      if (it->first < g_Time) {
        string s = it->second;  // key
        int p = dict[s].second;  // priority
        timepq.erase(it);
        prioritypq.erase(make_pair(p, s));
        dict.erase(s);
        LRUdict[p].remove(s);
      } else {
        break;
      }
    }
    
    // remove low priority
    int len = dict.size();
    while (len > maxItems) {
      auto it = prioritypq.begin();
      int p = it->first;
      // get the key at the back of the list
      string s = LRUdict[p].back();
      LRUdict[p].pop_back();
      int t = dict[s].first;
      dict.erase(s);
      timepq.erase(make_pair(t, s));
      prioritypq.erase(make_pair(p, s));
      len--;
    }
    
    
  }
  



  
  void Set(std::string key, CacheData value, int priority, int expiryInSecs) {
    // ... the interviewee does not need to implement this now.
    // Assume that this will add this key, value pair to the cache
    timepq.insert(make_pair(g_Time + expiryInSecs, key));
    prioritypq.insert(make_pair(priority, key));
    dict[key] = {g_Time + expiryInSecs, priority};
    LRUdict[priority].push_front(key);
    
    EvictItems();
  }
  
  
  
  CacheData* Get(std::string key) {
    // ... the interviewee does not need to implement this now.
    // Assume that this will return the value for the key in the cache
    // TODO: move it to the front
    auto it = dict.find(key);
    if (it != dict.end()) {
      LRUdict[it->second.second].remove(key);
      LRUdict[it->second.second].push_front(key);
    }
    
    return nullptr;
  }
  
  void SetMaxItems(int numItems) {
    maxItems = numItems;
    EvictItems();
  }

  
  void DebugPrintKeys() {
    // ... the interviewee does not need to implement this now.
    // Prints all the keys in the cache for debugging purposes
    for (auto ele : dict ) {
      cout << ele.first << "," ;
    }
    cout << "  " << endl ;
  }
  
};


int main() {

  PriorityExpiryCache c(5);
  c.Set("A", 1, 5,  100 );
  c.Set("B", 2, 15, 3   );
  c.Set("C", 3, 5,  10  );
  c.Set("D", 4, 1,  15  );
  c.Set("E", 5, 5,  150 );
  c.Get("C");


  // Current time = 0
  c.SetMaxItems(5);
  // Keys in C = ["A", "B", "C", "D", "E"]
  // space for 5 keys, all 5 items are included
  c.DebugPrintKeys();

  // Sleep for 5 secs
  g_Time += 5;

  // Current time = 5
  c.SetMaxItems(4);
  // Keys in C = ["A", "C", "D", "E"]
  // "B" is removed because it is expired.  e3 < e5
  c.DebugPrintKeys();

  c.SetMaxItems(3);
  // Keys in C = ["A", "C", "E"]
  // "D" is removed because it the lowest priority
  // D's expire time is irrelevant.
  c.DebugPrintKeys();

  c.SetMaxItems(2);
  // Keys in C = ["C", "E"]
  // "A" is removed because it is least recently used."
  // A's expire time is irrelevant.
  c.DebugPrintKeys();

  c.SetMaxItems(1);
  // Keys in C = ["C"]
  // "E" is removed because C is more recently used (due to the Get("C") event).
  c.DebugPrintKeys();
  
  return 0;
}

