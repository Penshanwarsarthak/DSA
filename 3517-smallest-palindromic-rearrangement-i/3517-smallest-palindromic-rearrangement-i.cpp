class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans(s.size(), ' ');

        int left = 0;
        int right = s.size() - 1;

        for (int i = 0; i < 26; i++) {
            while (cnt[i] >= 2) {
                ans[left++] = char('a' + i);
                ans[right--] = char('a' + i);
                cnt[i] -= 2;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1) {
                ans[left] = char('a' + i);
                break;
            }
        }

        return ans;
    }
};