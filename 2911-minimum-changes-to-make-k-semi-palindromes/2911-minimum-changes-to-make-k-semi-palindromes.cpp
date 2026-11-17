class Solution {
public:
    int minimumChanges(string s, int k) {
        int n=s.size(), INF=1e9;
        vector<vector<int>> cost(n,vector<int>(n,INF));

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int len=j-i+1;

                for(int d=1;d<len;d++) {
                    if(len%d) continue;

                    int cnt=0;

                    for(int x=0;x<d;x++) {
                        int l=i+x, r=j-d+1+x;

                        while(l<r) {
                            cnt+=s[l]!=s[r];
                            l+=d;
                            r-=d;
                        }
                    }

                    cost[i][j]=min(cost[i][j],cnt);
                }
            }
        }

        vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
        dp[n][0]=0;

        for(int i=n-1;i>=0;i--)
            for(int j=1;j<=k;j++)
                for(int x=i+1;x<n;x++)
                    if(dp[x+1][j-1]!=INF)
                        dp[i][j]=min(dp[i][j],cost[i][x]+dp[x+1][j-1]);

        return dp[0][k];
    }
};