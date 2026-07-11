class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vector<int> comp;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);

                for (int v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            int vertices = comp.size();
            int degreeSum = 0;

            for (int node : comp)
                degreeSum += graph[node].size();

            if (degreeSum == vertices * (vertices - 1))
                ans++;
        }

        return ans;
    }
};