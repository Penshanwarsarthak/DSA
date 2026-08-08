class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suffix(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                suffix[i] = suffix[i + 1] + 1;
                j--;
            } else {
                suffix[i] = suffix[i + 1];
            }
        }

        vector<int> ans;
        int pos = 0;
        bool changed = false;

        for (int i = 0; i < n && ans.size() < m; i++) {

            if (word1[i] == word2[pos]) {
                ans.push_back(i);
                pos++;
            }

            else if (!changed) {
                int remaining = m - pos - 1;

                if (n - i - 1 >= remaining &&
                    suffix[i + 1] >= remaining) {

                    ans.push_back(i);
                    pos++;
                    changed = true;
                }
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};