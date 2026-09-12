class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& a) {
        int n=a.size();
        vector<array<long long,4>> v(n);
        for(int i=0;i<n;i++) v[i]={a[i][0],a[i][1],a[i][2],i};
        sort(v.begin(),v.end());

        vector<vector<pair<long long,vector<int>>>> dp(n+1,
            vector<pair<long long,vector<int>>>(5));

        for(int i=n-1;i>=0;i--)
            for(int k=1;k<=4;k++) {
                dp[i][k]=dp[i+1][k];

                int j=upper_bound(v.begin()+i+1,v.end(),
                    array<long long,4>{v[i][1],LLONG_MAX,0,0})-v.begin();

                auto x=dp[j][k-1];
                x.first+=v[i][2];
                x.second.push_back(v[i][3]);
                sort(x.second.begin(),x.second.end());

                if(x.first>dp[i][k].first ||
                  (x.first==dp[i][k].first && x.second<dp[i][k].second))
                    dp[i][k]=x;
            }

        return dp[0][4].second;
    }
};