class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowDig = floor(log10(low)) + 1;
        int highDig = floor(log10(high)) + 1;
        string s = "123456789";
        vector<int> ans;
        for(int i = 1; i<=9; i++){
            bool push = false;
            for(int j = lowDig; j<=highDig; j++){
                if(i-1+j > 9) break;
                string temp = s.substr(i-1, j);

                if(temp.length() > 0 && stoi(temp) >= low && stoi(temp) <= high){
                    ans.push_back(stoi(temp));
                    push = true;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};