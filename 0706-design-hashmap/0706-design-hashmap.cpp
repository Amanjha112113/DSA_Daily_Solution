class MyHashMap {
private:
        unordered_map<int, int> myHashMap;

public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        myHashMap[key] = value;
    }
    
    int get(int key) {
        if(myHashMap.find(key) == myHashMap.end()) {
            return -1;
        }
        return myHashMap[key];
    }
    
    void remove(int key) {
        myHashMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */