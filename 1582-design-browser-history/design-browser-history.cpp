class BrowserHistory {
public:
    struct Node {
        string url;
        Node* prev;
        Node* next;

        Node(string s) {
            url = s;
            prev = next = NULL;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);

        // remove forward history
        curr->next = NULL;

        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev){
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next){
            curr = curr->next;
        }
        return curr->url;
    }
};