class LRUCache {
private:
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache_map;
    std::list<std::pair<int, int>> cache_list;
    int capacity;
    void move_to_front(int key) {
        auto node_it = cache_map[key];
        cache_list.splice(cache_list.begin(), cache_list, node_it);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }

        move_to_front(key);
        return cache_map[key]->second; 
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            cache_map[key]->second = value;
            move_to_front(key);
            return;
        }

        if (cache_list.size() == capacity) {
            int key_to_remove = cache_list.back().first;
            cache_map.erase(key_to_remove);
            cache_list.pop_back();
        }

        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */