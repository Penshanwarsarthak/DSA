class Solution {
public:

    long long gcd(long long a, long long b) {

        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b) {

        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();

        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long count = 0;

            for (int mask = 1; mask < (1 << n); mask++) {

                long long common = 1;
                int selected = 0;

                for (int i = 0; i < n; i++) {

                    if (mask & (1 << i)) {

                        selected++;

                        common = lcm(common, coins[i]);

                        if (common > mid) {
                            break;
                        }
                    }
                }

                if (common > mid)
                    continue;

                if (selected % 2 == 1) {
                    count += mid / common;
                }

                else {
                    count -= mid / common;
                }
            }

            if (count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};