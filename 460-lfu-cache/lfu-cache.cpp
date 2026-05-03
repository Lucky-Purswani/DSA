class LFUCache {
    int capacity ;
    unordered_map<int,vector<int>>m;
    map<pair<int,int>, int>FreUsed;
    int time ;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        // cout<<capacity<<endl;
        this->time = 0;
    }
    
    int get(int key) {
        time++;
        // for(auto i: m) {
        //     cout<<i.first<<" ";
        // }cout<<endl;
        if(m.count(key)) {
            int fre = m[key][1];
            int used = m[key][2];

            FreUsed.erase({fre, used});
            FreUsed[{fre+1, time}] = key;

            m[key][1] = fre+1;
            m[key][2] = time;

            return m[key][0];
        }
        return -1;
    }
    
    void put(int key, int value) {
        time++;
        if(m.count(key)) {
            int fre = m[key][1];
            int used = m[key][2];

            FreUsed.erase({fre, used});
            FreUsed[{fre+1, time}] = key;

            m[key][0] = value;
            m[key][1]++;
            m[key][2] = time; 
            


            return ;
        }
        if(m.size() >= capacity) {
            auto it = FreUsed.begin();

            cout<<it->second<<endl;
            m.erase(it->second);
            FreUsed.erase(it->first);
           

            int fre = 1;
            int used = time;
            m[key]= {value, fre, used};
            FreUsed[{fre , used}] = key;
        }
        else {
            int fre = 1;
            int used = time;
            m[key]= {value, fre, used};
            FreUsed[{fre , used}] = key;
        }



    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */