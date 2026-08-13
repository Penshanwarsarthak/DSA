class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        if (a.rightChar == b.leftChar) {

            if (a.prefix == a.len)
                res.prefix = a.len + b.prefix;

            if (b.suffix == b.len)
                res.suffix = b.len + a.suffix;

            res.best = max(a.best, b.best);
            res.best = max(res.best, a.suffix + b.prefix);

        } else {
            res.best = max(a.best, b.best);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {

        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};