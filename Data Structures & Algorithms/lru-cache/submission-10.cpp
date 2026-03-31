class LRUCache {
    int capacity;
    
    // stores the key order 
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) : capacity(capacity){
        
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            int value = cache[key].first;
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key].second = --order.end();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
            cache.erase(key);
        }
        // LRU --> MRU
        if(cache.size() == capacity){
            auto front = order.front();
            order.erase(cache[front].second);
            cache.erase(front);
        } 

        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
