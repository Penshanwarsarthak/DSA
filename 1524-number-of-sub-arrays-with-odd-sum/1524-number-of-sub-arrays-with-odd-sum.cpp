class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        long long odd=0, even=1, sum=0, ans=0;

        for(int x:arr) {
            sum+=x;

            if(sum%2) {
                ans+=even;
                odd++;
            } else {
                ans+=odd;
                even++;
            }
            ans%=MOD;
        }
        return ans;
    }
};