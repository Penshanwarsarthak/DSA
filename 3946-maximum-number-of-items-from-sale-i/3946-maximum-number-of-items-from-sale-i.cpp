class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = INT_MAX;
        vector<int> dp(budget + 1, 0);

        for (auto &x : items)
            mn = min(mn, x[1]);

        for (int i = 0; i < n; i++) {
            int freeCnt = 0;

            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0)
                    freeCnt++;

            int price = items[i][1];

            for (int b = budget; b >= price; b--)
                dp[b] = max(dp[b], dp[b - price] + freeCnt + 1);
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = max(ans, dp[b] + (budget - b) / mn);

        return ans;
    }
};