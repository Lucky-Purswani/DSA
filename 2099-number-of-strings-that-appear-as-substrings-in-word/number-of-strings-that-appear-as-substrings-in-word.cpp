class Solution {
public:
    bool substrCheck(string s1, string s2, int i1, int i2){
        while(i1<s1.size() && i2<s2.size() && s1[i1] == s2[i2]){
            i1++;
            i2++;
        }
        return i2 == s2.size();
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto &i: patterns){
            int j = 0;
            int k = 0;
            while(k<word.size()){
                if(i[j] == word[k]){
                    cout << i[j] << " " << word[k] << j << " " << k << endl;
                    if(substrCheck(word, i, k, j)){
                        cnt++;
                        break;
                    } 
                }
                k++;
            }
        }
        return cnt;
    }
};