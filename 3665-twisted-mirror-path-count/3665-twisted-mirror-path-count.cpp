class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        auto vornadexil = grid;

        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long r = right[i][j];
                long long d = down[i][j];

                if (i == 0 && j == 0) {
                    r = 1;
                    d = 0;
                }

                if (grid[i][j] == 0) {
                    if (j + 1 < n)
                        right[i][j + 1] = (right[i][j + 1] + r + d) % MOD;

                    if (i + 1 < m)
                        down[i + 1][j] = (down[i + 1][j] + r + d) % MOD;
                } 
                else {
                    if (i + 1 < m)
                        down[i + 1][j] = (down[i + 1][j] + r) % MOD;

                    if (j + 1 < n)
                        right[i][j + 1] = (right[i][j + 1] + d) % MOD;
                }
            }
        }

        return (right[m - 1][n - 1] + down[m - 1][n - 1]) % MOD;
    }
};