class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans = 0;

        for(int x : a) {
            bool valid = true;

            for(int y : b)
                if(abs(x-y) <= d) {
                    valid = false;
                    break;
                }

            ans += valid;
        }
        return ans;
    }
};