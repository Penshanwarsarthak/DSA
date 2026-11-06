class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = q.size(), l = 0, r = 0;
        vector<int> ans(m), idx(m);
        unordered_map<int,int> mp;

        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return q[a] < q[b];
        });

        for(int i : idx) {
            while(r < logs.size() && logs[r][1] <= q[i])
                mp[logs[r++][0]]++;

            while(l < r && logs[l][1] < q[i] - x) {
                if(--mp[logs[l][0]] == 0)
                    mp.erase(logs[l][0]);
                l++;
            }

            ans[i] = n - mp.size();
        }

        return ans;
    }
};