
class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* last;
    int capacity;
    int size;
    unordered_map<int, Node*> map;

    void remove(Node* keyNode) {
        if (keyNode->prev) keyNode->prev->next = keyNode->next;
        if (keyNode->next) keyNode->next->prev = keyNode->prev;
        if (last == keyNode) last = keyNode->prev;
        if (head == keyNode) head = keyNode->next;
        map.erase(keyNode->key);
        delete keyNode;
        size--;
    }

    void insert(int key, int value) {
        Node* temp = new Node(key, value);
        if (!head) {
            head = last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
        map[key] = temp;
        size++;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0), head(nullptr), last(nullptr) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node* keyNode = map[key];
        int val = keyNode->val;
        remove(keyNode);
        insert(key, val);
        return val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            remove(map[key]);
        }
        if (size == capacity) {
            remove(head);
        }
        insert(key, value);
    }
};
