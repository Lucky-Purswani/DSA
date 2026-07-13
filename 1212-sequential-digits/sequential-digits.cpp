class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowDig = floor(log10(low)) + 1;
        int highDig = floor(log10(high)) + 1;

        string s = "123456789";
        vector<int> ans;

        for(int i = 0; i < 9; i++) {
            for(int len = lowDig; len <= highDig; len++) {
                if(i + len > 9) break;

                int num = stoi(s.substr(i, len));

                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};