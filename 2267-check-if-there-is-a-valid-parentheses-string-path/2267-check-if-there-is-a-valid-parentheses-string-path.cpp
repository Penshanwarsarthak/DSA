class Solution {
public:
    int m,n;
    vector<string> g;
    int dp[101][101][101];

    bool dfs(int i,int j,int open) {
        if(open<0) return false;

        open += (g[i][j]=='(' ? 1 : -1);

        if(open<0) return false;
        if(i==m-1 && j==n-1) return open==0;

        int &x=dp[i][j][open];
        if(x!=-1) return x;

        return x = (i+1<m && dfs(i+1,j,open)) ||
                   (j+1<n && dfs(i,j+1,open));
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();
        if((m+n-1)%2) return false;

        g.resize(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                g[i]+=grid[i][j];

        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0);
    }
};