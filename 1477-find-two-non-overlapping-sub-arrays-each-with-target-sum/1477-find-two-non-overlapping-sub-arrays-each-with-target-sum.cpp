class Solution {
public:
    int minSumOfLengths(vector<int>& a, int t) {
        int n=a.size(),l=0,sum=0,ans=1e9,b=1e9;
        vector<int> dp(n,1e9);

        for(int r=0;r<n;r++){
            sum+=a[r];
            while(sum>t) sum-=a[l++];

            if(sum==t){
                int len=r-l+1;
                if(l) ans=min(ans,dp[l-1]+len);
                b=min(b,len);
            }
            dp[r]=b;
        }
        return ans==1e9?-1:ans;
    }
};