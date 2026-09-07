class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26);

        long long total = 0;

        for(char c : s) {
            long long add = (total + 1) % MOD;
            total = (total + add - dp[c-'a'] + MOD) % MOD;
            dp[c-'a'] = add;
        }

        return total;
    }
};