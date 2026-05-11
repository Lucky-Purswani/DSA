class Solution {
public:
    int count(vector<int> v, int target){
        int s = 0;
        int e = v.size() - 1;
        int idx = -1;

        while(s <= e){
            int m = s + (e - s) / 2;

            if(v[m] == target){
                idx = m;
                e = m - 1;
            }
            else if(v[m] < target){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }

        return idx;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        for(auto &i : mat){
            sort(i.begin(), i.end());
        }
        int cnt = 0;
        int r = 0;
        int currRow = 0;
        for(auto &i:mat){
            int idx = count(i, 1);
            if(idx != -1 && cnt < i.size()-idx){
                cnt = i.size()-idx;
                r = currRow;
            }
            currRow++;
        }
        return {r, cnt};

    }
};