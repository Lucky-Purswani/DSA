class Solution {
public:
    int maxDistance(string moves) {
        int u = 1;
        int d = -1;
        int l = -1;
        int r = 1;
        int cnt = 0;

        pair<int, int> cr = {0, 0};
        for(auto &i: moves){
            if(i == 'U'){
                cr.second += u;
            }
            else if(i == 'R'){
                cr.first += r;
            }
            else if(i == 'D'){
                cr.second += d;
            }
            else if(i == 'L'){
                cr.first += l;
            }
            else{
                cnt++;
            }
        }

        int ans = abs(0-cr.first) + abs(0-cr.second);
        ans+=cnt;
        return ans;
    }
};