class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int n = 8;

        if (source == target)
            return 0;

        // Different colored squares => bishop can never reach
        if ((source[0] + source[1]) % 2 !=
            (target[0] + target[1]) % 2)
            return -1;

        vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));

        queue<pair<pair<int, int>, int>> q;

        q.push({{source[0], source[1]}, 0});
        vis[source[0]][source[1]] = 1;

        int dr[] = {1, 1, -1, -1};
        int dc[] = {1, -1, 1, -1};

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            int i = pos.first;
            int j = pos.second;

            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];

                while (ni >= 1 && ni <= n &&
                       nj >= 1 && nj <= n) {

                    if (ni == target[0] && nj == target[1])
                        return moves + 1;

                    if (!vis[ni][nj]) {
                        vis[ni][nj] = 1;
                        q.push({{ni, nj}, moves + 1});
                    }

                    ni += dr[d];
                    nj += dc[d];
                }
            }
        }

        return -1;
    }
};