class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // move accessed pair to front (most recent)
        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }
    
    void put(int key, int value) {
        // If exists 
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        } 
        // If cache is full
        else if ((int)cache.size() == capacity) {
            // remove least recently used
            auto last = cache.back();
            mp.erase(last.first);           // last.first is the key (So remove it from map)
            cache.pop_back();               // Now pop from list as well
        }

        // insert new (key, value) at front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
