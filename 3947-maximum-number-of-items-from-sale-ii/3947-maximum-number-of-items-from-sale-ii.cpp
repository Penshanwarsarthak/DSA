class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = INT_MAX;
        vector<int> freq(n + 1), cnt(n + 1);

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, x[1]);
        }

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                cnt[i] += freq[j];

        vector<pair<int,int>> v;

        for (auto &x : items) {
            int price = x[1];
            int gain = cnt[x[0]] - 1;

            if (gain > 0 && price < 2 * mn)
                v.push_back({price, gain});
        }

        sort(v.begin(), v.end());

        long long ans = 0;

        for (auto [price, gain] : v) {
            int take = min(gain, budget / price);
            ans += 2LL * take;
            budget -= take * price;
        }
        ans += budget / mn;

        return ans;
    }
};