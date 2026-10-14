class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (1LL * num * 9 < sum) return "";

        string ans(num, '0');
        int i = 0;

        while (sum >= 9) {
            ans[i++] = '9';
            sum -= 9;
        }
        if (sum > 0) ans[i] = '0' + sum;

        return ans;
    }
};