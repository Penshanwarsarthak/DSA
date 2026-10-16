class Solution {
    static const int MOD = 1e9 + 7;
    using ll = long long;
    struct Node {
        ll sum = 0, sq = 0, lazy = 0;
    };
    vector<Node> st;
    int n;

    void push(int p, int l, int r) {
        if (!st[p].lazy || l == r) return;
        int m = (l + r) / 2;
        apply(p * 2, l, m, st[p].lazy);
        apply(p * 2 + 1, m + 1, r, st[p].lazy);
        st[p].lazy = 0;
    }

    void apply(int p, int l, int r, ll v) {
        st[p].sq = (st[p].sq + 2 * v * st[p].sum
                    + v * v % MOD * (r - l + 1)) % MOD;
        st[p].sum = (st[p].sum + v * (r - l + 1)) % MOD;
        st[p].lazy = (st[p].lazy + v) % MOD;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        update(p * 2, l, m, ql, qr);
        update(p * 2 + 1, m + 1, r, ql, qr);
        st[p].sum = (st[p * 2].sum + st[p * 2 + 1].sum) % MOD;
        st[p].sq = (st[p * 2].sq + st[p * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n);
        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + st[1].sq) % MOD;
        }
        return ans;
    }
};