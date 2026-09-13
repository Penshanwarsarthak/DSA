class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(), ans=0;
        map<pair<int,int>,int> mp;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) if(a[i][j])
                for(int x=0;x<n;x++)
                    for(int y=0;y<n;y++) if(b[x][y])
                        ans=max(ans,++mp[{i-x,j-y}]);

        return ans;
    }
};