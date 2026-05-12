class Solution {
public:
    int minimumEffort(vector<vector<int>>& shop) {

        sort(shop.begin(), shop.end(),
        [&](vector<int>& a, vector<int>& b) {

            return a[1] - a[0] >
                   b[1] - b[0];
        });

        int startR = shop[0][1];

        int bal = shop[0][1] - shop[0][0];

        int energy = 0;

        for(int i = 1; i < shop.size(); i++){

            int startA = shop[i][0];

            int req = shop[i][1];

            if(bal < req){

                energy += req - bal;

                bal = req;
            }

            bal -= startA;
        }

        return startR + energy;
    }
};