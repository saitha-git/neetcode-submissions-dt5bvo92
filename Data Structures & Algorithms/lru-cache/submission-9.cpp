class Node {
public:
    int key;
    int val; 
    Node* next;
    Node* prev;
    
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
    unordered_map<int, Node*> cache;
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    void push_front(Node* node)
    {
        Node* next = head->next;
        next->prev = node;
        node->next = next;
        node->prev = head;
        head->next = node;
        
    }

    void removeNode(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        return;  
    }

    int get(int key) {
        if ( cache.find(key) != cache.end() )
        {
            Node* node = cache[key];
            removeNode(node);
            push_front(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if ( cache.find(key) != cache.end() )
        {
            Node* node = cache[key];
            removeNode(node);
            node->val = val;  // Update the value
            push_front(cache[key]);
        }
        else
        {
            Node* node = new Node(key, val);
            cout << "key:" << key << "val:" << val << endl;
            cache[key] = node;
            push_front(cache[key]);
        }

        // Size check
        if (cache.size() > capacity)
        {
            Node* lru = tail->prev;
            removeNode(tail->prev);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
