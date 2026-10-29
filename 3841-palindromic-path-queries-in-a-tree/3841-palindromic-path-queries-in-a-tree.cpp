class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, bit;
    int timer = 0;

    void add(int i, int val, int n) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int queryBIT(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        vector<int> parent(n, -1);
        vector<pair<int, bool>> st = {{0, false}};

        while (!st.empty()) {
            auto [u, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            st.push_back({u, true});

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                st.push_back({v, false});
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            add(tin[u], mask, n);
            add(tout[u] + 1, mask, n);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                add(tin[u], delta, n);
                add(tout[u] + 1, delta, n);

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int mask = queryBIT(tin[u])
                         ^ queryBIT(tin[v])
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};