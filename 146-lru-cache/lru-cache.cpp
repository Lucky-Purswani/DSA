class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
};
class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int limit;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            addNode(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    void addNode(Node* nodeToAdd){
        head->next->prev = nodeToAdd;
        nodeToAdd->next = head->next;
        head->next = nodeToAdd;
        nodeToAdd->prev = head;
    }

    void deleteNode(Node* deleteNode){
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
    }



    void put(int key, int value) {
        //Key already exist
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            deleteNode(existing);
            delete existing;
            mp.erase(key);
        }
        //Size if full
        if(limit == mp.size()){
            Node* temp = tail->prev;
            deleteNode(temp);
            mp.erase(temp->key);
            delete temp;
        }

        // Add new node to front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */