class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1);
        for (int x : nums)
            cnt[x]++;

        vector<long long> cntG(mx + 1);

        for (int i = mx; i >= 1; i--) {
            long long total = 0;

            for (int j = i; j <= mx; j += i) {
                total += cnt[j];
                cntG[i] -= cntG[j];
            }

            cntG[i] += total * (total - 1) / 2;
        }

        for (int i = 2; i <= mx; i++)
            cntG[i] += cntG[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(
                upper_bound(cntG.begin(), cntG.end(), q) - cntG.begin()
            );
        }

        return ans;
    }
};