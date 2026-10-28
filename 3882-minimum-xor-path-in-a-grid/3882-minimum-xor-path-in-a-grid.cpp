class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MAX_XOR = 1024;

        vector<vector<bool>> prev(n, vector<bool>(MAX_XOR, false));
        vector<vector<bool>> curr(n, vector<bool>(MAX_XOR, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), false);

                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    curr[j][val] = true;
                    continue;
                }

                if (i > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (prev[j][x])
                            curr[j][x ^ val] = true;
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < MAX_XOR; x++) {
                        if (curr[j - 1][x])
                            curr[j][x ^ val] = true;
                    }
                }
            }

            swap(prev, curr);
        }

        for (int x = 0; x < MAX_XOR; x++) {
            if (prev[n - 1][x])
                return x;
        }

        return 0;
    }
};