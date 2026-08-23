class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQuestion = 0;
        int rightQuestion = 0;

        for (int i = 0; i < n / 2; i++) {

            if (num[i] == '?')
                leftQuestion++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {

            if (num[i] == '?')
                rightQuestion++;
            else
                rightSum += num[i] - '0';
        }

        if ((leftQuestion + rightQuestion) % 2 == 1)
            return true;

        int difference = leftSum - rightSum;

        int required = 9 * (rightQuestion - leftQuestion) / 2;

        if (difference == required)
            return false;

        return true;
    }
};