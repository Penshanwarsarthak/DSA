class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> l, r;
        long long sumL = 0, sumR = 0;
        vector<long long> cost;

        auto balance = [&]() {
            while(l.size() > (x+1)/2) {
                int v = *l.rbegin();
                l.erase(l.find(v));
                sumL -= v;
                r.insert(v);
                sumR += v;
            }

            while(l.size() < (x+1)/2 && !r.empty()) {
                int v = *r.begin();
                r.erase(r.find(v));
                sumR -= v;
                l.insert(v);
                sumL += v;
            }
        };

        for(int i = 0; i < n; i++) {
            if(l.empty() || nums[i] <= *l.rbegin()) {
                l.insert(nums[i]);
                sumL += nums[i];
            } else {
                r.insert(nums[i]);
                sumR += nums[i];
            }

            if(i >= x) {
                int v = nums[i-x];

                if(l.find(v) != l.end()) {
                    l.erase(l.find(v));
                    sumL -= v;
                } else {
                    r.erase(r.find(v));
                    sumR -= v;
                }
            }

            balance();

            if(i >= x-1) {
                long long med = *l.rbegin();

                cost.push_back(
                    med * l.size() - sumL +
                    sumR - med * r.size()
                );
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, INF));

        dp[0][0] = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                if(dp[i][j] == INF) continue;

                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

                if(j < k && i+x <= n)
                    dp[i+x][j+1] = min(
                        dp[i+x][j+1],
                        dp[i][j] + cost[i]
                    );
            }
        }

        return dp[n][k];
    }
};