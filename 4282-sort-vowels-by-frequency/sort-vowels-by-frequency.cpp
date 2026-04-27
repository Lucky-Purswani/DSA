class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string sortVowels(string s) {
        unordered_map<char,int> m;
        for(char ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                m[ch]++;
            }
        }
        vector<pair<char,int>> v;
        for(auto &p:m){
            v.push_back(p);
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        stack<char> st;
        for(int i=0;i<v.size();i++){
            while(v[i].second--)
            st.push(v[i].first);
        }
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                char ch=st.top();
                s[i]=ch;
                st.pop();
            }
        }
        return s;
    }
};