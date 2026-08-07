class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            st.erase(word);

            for(int i = 0; i<word.size(); i++){
                char og = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, step+1});
                        cout << word << " ";
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};