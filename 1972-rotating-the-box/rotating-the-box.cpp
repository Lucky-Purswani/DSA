class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        // for(int i = 0; i < v.size(); i++) {
        //     for(int j = 0; j < v[i].size(); j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;

        // }
        // cout << endl;

        for(int i = 0; i<n; i++){
            for(int j = m-2; j>=0; j--){
                if(v[i][j] == '#'){
                    int temp = j;
                    while(temp < m-1 && v[i][temp+1] == '.'){
                        swap(v[i][temp], v[i][temp+1]);
                        temp++;
                    }
                }
            }
        }
        
        // for(int i = 0; i < v.size(); i++) {
        //     for(int j = 0; j < v[i].size(); j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<char>> res(m, vector<char>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[j][n - 1 - i] = v[i][j];
            }
        }

        return res;
    }
};