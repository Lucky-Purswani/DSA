class Solution {
public:

    // Reverse a string in-place
    void reverseH(string &s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }

    // Remove leading + trailing spaces
    string trim(const string &s) {
        int i = 0, j = s.length() - 1;

        // skip leading spaces
        while (i <= j && s[i] == ' ') i++;

        // skip trailing spaces
        while (j >= i && s[j] == ' ') j--;

        // if all spaces
        if (i > j) return "";

        return s.substr(i, j - i + 1);
    }

    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (char ch : s) {

            // if space → process current word
            if (ch == ' ') {
                if (!word.empty()) {
                    reverseH(word);          // reverse word
                    ans += word + ' ';       // add to answer
                    word.clear();            // reset
                }
            } else {
                word += ch;                  // build word
            }
        }

        // process last word
        if (!word.empty()) {
            reverseH(word);
            ans += word;
        }

        // clean spaces and reverse whole string
        ans = trim(ans);
        reverseH(ans);

        return ans;
    }
};