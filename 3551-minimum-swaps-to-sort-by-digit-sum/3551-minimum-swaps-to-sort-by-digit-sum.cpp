class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<pair<int, int>> a;

        for (int x : nums) {
            int s = 0, t = x;
            while (t) {
                s += t % 10;
                t /= 10;
            }
            a.push_back({s, x});
        }

        sort(a.begin(), a.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i, len = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                len++;
            }

            if (len > 1) ans += len - 1;
        }
        return ans;
    }
};