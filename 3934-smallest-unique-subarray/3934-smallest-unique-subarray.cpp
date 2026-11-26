class Solution {
    using ll = long long;
    const ll B1 = 100019, B2 = 100043;
    const ll M1 = 1e9 + 7, M2 = 1e9 + 9;

    vector<ll> h1, h2, p1, p2;

    bool check(int len) {
        map<pair<ll,ll>, int> freq;
        int n = h1.size() - 1;

        for (int i = 0; i + len <= n; i++) {
            ll x = (h1[i+len] - h1[i] * p1[len] % M1 + M1) % M1;
            ll y = (h2[i+len] - h2[i] * p2[len] % M2 + M2) % M2;

            freq[{x, y}]++;
        }

        for (auto &[key, count] : freq)
            if (count == 1) return true;

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n+1);
        h2.resize(n+1);
        p1.resize(n+1, 1);
        p2.resize(n+1, 1);

        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i+1] = (h2[i] * B2 + nums[i]) % M2;

            p1[i+1] = p1[i] * B1 % M1;
            p2[i+1] = p2[i] * B2 % M2;
        }

        int l = 1, r = n;

        while (l < r) {
            int mid = l + (r-l)/2;

            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};