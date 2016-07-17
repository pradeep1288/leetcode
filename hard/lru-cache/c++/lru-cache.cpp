struct cacheData {
    int key;
    int value;
    cacheData *next;
    cacheData *prev;
};

class LRUCache{
    
private:
    std::map<int, cacheData*> _myMap;
    cacheData *_myCache;
    cacheData *_head;
    cacheData *_tail;
    int _freeIndex;
    int _maxCapacity;
public:
    LRUCache(int capacity): _freeIndex(0) {
        _myCache = new cacheData[capacity]; 
        _maxCapacity = capacity;
        _head = new cacheData;
        _tail = new cacheData;
        _head->next = _tail;
        _head->prev = NULL;
        _tail->next = NULL;
        _tail->prev = _head;
    }
    
    int get(int key) {
        std::map<int,cacheData*>::iterator it = _myMap.find(key);
        if (it != _myMap.end()) {
            unlink(it->second);
            insert(it->second);
            return it->second->value;
        }
        return -1;
        
    }
    
    void set(int key, int value) {
        std::map<int, cacheData*>::iterator it = _myMap.find(key);
        if (it != _myMap.end()) {
            unlink(it->second);
            it->second->value = value;
            insert(it->second);
        } else {
            cacheData* node = NULL;
            if (_freeIndex >= _maxCapacity) {
                node = _tail->prev;
                unlink(node);
                _myMap.erase(node->key);
                
            } else {
                node = _myCache + _freeIndex;
                _freeIndex++;
                
            }
            node->value = value;
            node->key = key;
            insert(node);
            _myMap.insert(std::make_pair(key, node));
        }
    }
    
    void insert(cacheData *data) {
        data->next = _head->next;
        data->prev = _head;
        _head->next = data;
        data->next->prev = data;
    }
    
    void unlink(cacheData *data) {
        data->next->prev = data->prev;
        data->prev->next = data->next;
    }
};
