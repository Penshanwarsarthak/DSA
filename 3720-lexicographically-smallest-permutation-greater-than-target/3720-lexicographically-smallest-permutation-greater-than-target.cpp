class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = n - 1; i >= 0; i--) {

            vector<int> temp = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (temp[c] == 0)
                    continue;

                string ans = target.substr(0, i);

                ans += char('a' + c);

                temp[c]--;

                for (int j = 0; j < 26; j++) {

                    while (temp[j] > 0) {
                        ans += char('a' + j);
                        temp[j]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};