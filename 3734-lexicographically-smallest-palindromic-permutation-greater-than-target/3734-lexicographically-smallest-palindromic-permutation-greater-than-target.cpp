class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int middle = -1;
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                middle = i;
            }
        }

        if (odd > 1) {
            return "";
        }

        vector<int> halfCnt(26, 0);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        vector<int> rem = halfCnt;
        string left = "";
        bool possible = true;

        for (int i = 0; i < half; i++) {

            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            left += target[i];
            rem[x]--;
        }

        if (possible) {

            string ans = left;

            if (n % 2 == 1) {
                ans += char('a' + middle);
            }

            string right = left;
            reverse(right.begin(), right.end());

            ans += right;

            if (ans > target) {
                return ans;
            }
        }


        for (int i = half - 1; i >= 0; i--) {

            rem = halfCnt;

            bool ok = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
            }

            if (!ok) {
                continue;
            }

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (rem[c] == 0) {
                    continue;
                }

                string newLeft = target.substr(0, i);

                newLeft += char('a' + c);

                rem[c]--;

                for (int j = 0; j < 26; j++) {

                    while (rem[j] > 0) {
                        newLeft += char('a' + j);
                        rem[j]--;
                    }
                }

                string ans = newLeft;

                if (n % 2 == 1) {
                    ans += char('a' + middle);
                }

                string right = newLeft;
                reverse(right.begin(), right.end());

                ans += right;

                return ans;
            }
        }

        return "";
    }
};