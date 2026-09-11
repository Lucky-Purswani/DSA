class Solution {
public:
    int countRotations(string s, int k) {
        // aacb
        // ba ac
        // acba -> a - acb -> bcaa
        // abca -> ab-ca -> ba-ac
        int ans = 0;

        for(int i = 0; i<s.size(); i++){
            string a = s.substr(0, i+1);
            string b = s.substr(i+1);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            string temp = a+b;
            reverse(temp.begin(), temp.end());

            int same = 0;
            for(int i = 1; i<s.size(); i++){
                if(temp[i] == temp[i-1]) same++;
            }
            if(same == k) ans++;
        }

        return ans;
    }
};