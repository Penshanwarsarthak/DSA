class Solution {
public:

    int solve(int l, int r, vector<int>& stoneValue,
              vector<int>& prefix,
              vector<vector<int>>& dp) {

        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {

            int leftSum = prefix[k + 1] - prefix[l];

            int rightSum = prefix[r + 1] - prefix[k + 1];

            if (leftSum < rightSum) {

                ans = max(
                    ans,
                    leftSum + solve(
                        l, k,
                        stoneValue,
                        prefix,
                        dp
                    )
                );
            }

            else if (rightSum < leftSum) {

                ans = max(
                    ans,
                    rightSum + solve(
                        k + 1, r,
                        stoneValue,
                        prefix,
                        dp
                    )
                );
            }

            else {

                ans = max(
                    ans,
                    max(
                        leftSum + solve(
                            l, k,
                            stoneValue,
                            prefix,
                            dp
                        ),

                        rightSum + solve(
                            k + 1, r,
                            stoneValue,
                            prefix,
                            dp
                        )
                    )
                );
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return solve(
            0,
            n - 1,
            stoneValue,
            prefix,
            dp
        );
    }
};