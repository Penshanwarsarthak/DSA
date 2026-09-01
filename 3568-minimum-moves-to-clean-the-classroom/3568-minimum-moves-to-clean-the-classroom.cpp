class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    id[r][c] = k++;
                }
            }
        }

        int allMask = (1 << k) - 1;

        if (k == 0)
            return 0;

        int states = m * n * (energy + 1) * (1 << k);

        vector<char> visited(states, 0);

        auto getId = [&](int r, int c, int e, int mask) {
            return (((r * n + c) * (energy + 1) + e)
                    * (1 << k) + mask);
        };

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, 0});

        visited[getId(sr, sc, energy, 0)] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == allMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int nmask = mask;

                    if (id[nr][nc] != -1) {
                        nmask |= (1 << id[nr][nc]);
                    }

                    if (ne == 0 &&
                        classroom[nr][nc] != 'R' &&
                        nmask != allMask) {
                        continue;
                    }
                    int stateId = getId(nr, nc, ne, nmask);

                    if (visited[stateId])
                        continue;

                    visited[stateId] = 1;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask
                    });
                }
            }
            moves++;
        }
        return -1;
    }
};