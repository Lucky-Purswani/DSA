class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v(123);
        for(auto &i:s){
            int freq = v[i].second;
            v[i] = {i, freq+1};
        }
        auto lambda = [&](pair<char, int> p1, pair<char, int> p2){
            return p1.second > p2.second;
        };
        sort(v.begin(), v.end(), lambda);

        string res;
        for(int i = 0; i<123; i++){
            string temp = string(v[i].second, v[i].first);
            res += temp;
        }
        return res;
    }
};