class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(32);

        for (int x : nums)
            for (int b = 0; b < 32; b++)
                if (x & (1 << b)) cnt[b]++;

        long long ans = 0;

        while (k--) {
            long long x = 0;
            for (int b = 31; b >= 0; b--)
                if (cnt[b]) {
                    x |= 1LL << b;
                    cnt[b]--;
                }

            ans = (ans + x * x) % MOD;
        }
        return ans;
    }
};