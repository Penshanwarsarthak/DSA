class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        long long k = 1LL * k1 + k2, ans = 0;
        vector<int> d(a.size());

        for (int i = 0; i < a.size(); i++) {
            d[i] = abs(a[i] - b[i]);
            ans += 1LL * d[i] * d[i];
        }

        if (accumulate(d.begin(), d.end(), 0LL) <= k) return 0;

        int l = 0, r = *max_element(d.begin(), d.end());

        while (l < r) {
            int m = l + (r - l) / 2;
            long long need = 0;

            for (int x : d)
                need += max(0, x - m);

            if (need <= k) r = m;
            else l = m + 1;
        }

        for (int x : d) {
            int y = min(x, l);
            ans -= 1LL * x * x - 1LL * y * y;
            k -= x - y;
        }

        for (int x : d) {
            if (k == 0) break;
            if (x >= l && l > 0) {
                ans -= 2LL * l - 1;
                k--;
            }
        }
        return ans;
    }
};