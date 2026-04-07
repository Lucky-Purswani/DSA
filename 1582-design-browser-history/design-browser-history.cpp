class BrowserHistory {
public:
    vector<string> history;
    int curr;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        history.resize(curr+1);
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr = curr - steps >= 0 ? curr-steps : 0;
        return history[curr];
    }
    
    string forward(int steps) {
        curr = curr + steps < history.size() ? curr+steps : history.size()-1;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */



//This is soln using DLL:-
// class BrowserHistory {
// public:
//     struct Node {
//         string url;
//         Node* prev;
//         Node* next;

//         Node(string s) {
//             url = s;
//             prev = next = NULL;
//         }
//     };

//     Node* curr;

//     BrowserHistory(string homepage) {
//         curr = new Node(homepage);
//     }
    
//     void visit(string url) {
//         Node* newNode = new Node(url);

//         // remove forward history
//         curr->next = NULL;

//         newNode->prev = curr;
//         curr->next = newNode;
//         curr = newNode;
//     }
    
//     string back(int steps) {
//         while(steps-- && curr->prev){
//             curr = curr->prev;
//         }
//         return curr->url;
//     }
    
//     string forward(int steps) {
//         while(steps-- && curr->next){
//             curr = curr->next;
//         }
//         return curr->url;
//     }
// };