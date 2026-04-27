class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();

        // function to check vowel
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || 
                   ch == 'o' || ch == 'u';
        };

        // stores {character, frequency}
        vector<pair<char, int>> v(26);

        // stores first occurrence index of each vowel
        vector<int> firstPos(26, -1);

        // count frequency + first occurrence
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                int idx = s[i] - 'a';

                // increase frequency
                v[idx] = {s[i], v[idx].second + 1};

                // store first occurrence only once
                if (firstPos[idx] == -1) {
                    firstPos[idx] = i;
                }
            }
        }

        // sort by:
        // 1. higher frequency first
        // 2. if same frequency -> earlier first occurrence first
        sort(v.begin(), v.end(), [&](auto &a, auto &b) {

            // if one frequency is 0, push it behind
            if (a.second == 0) return false;
            if (b.second == 0) return true;

            // higher frequency first
            if (a.second != b.second) {
                return a.second > b.second;
            }

            // same frequency -> earlier first occurrence first
            return firstPos[a.first - 'a'] < firstPos[b.first - 'a'];
        });

        string temp = "";

        // make sorted vowel string
        for (int i = 0; i < 26; i++) {
            temp += string(v[i].second, v[i].first);
        }

        int j = 0;

        // replace only vowels in original string
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = temp[j++];
            }
        }

        return s;
    }
};