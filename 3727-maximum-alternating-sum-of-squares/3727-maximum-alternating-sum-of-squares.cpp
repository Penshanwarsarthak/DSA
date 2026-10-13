class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += (i < nums.size() / 2 ? -1LL : 1LL) * nums[i] * nums[i];

        return ans;
    }
};