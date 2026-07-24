class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_set<int> pairs;
        vector<bool> seen(2048, false);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairs.insert(nums[i] ^ nums[j]);
            }
        }

        for (int x : pairs) {
            for (int num : nums) {
                seen[x ^ num] = true;
            }
        }

        int ans = 0;
        for (bool x : seen)
            if (x) ans++;

        return ans;
    }
};