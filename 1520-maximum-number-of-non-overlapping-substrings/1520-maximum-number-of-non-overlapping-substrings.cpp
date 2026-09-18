class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> l(26,n),r(26,-1);

        for(int i=0;i<n;i++)
            l[s[i]-'a']=min(l[s[i]-'a'],i),
            r[s[i]-'a']=i;

        vector<pair<int,int>> v;

        for(int c=0;c<26;c++) {
            if(r[c]<0) continue;

            int L=l[c],R=r[c];
            for(int i=L;i<=R;i++) {
                int x=s[i]-'a';
                if(l[x]<L) { R=-1; break; }
                R=max(R,r[x]);
            }

            if(R!=-1) v.push_back({R,L});
        }

        sort(v.begin(),v.end());

        vector<string> ans;
        int last=-1;

        for(auto [R,L]:v)
            if(L>last)
                ans.push_back(s.substr(L,R-L+1)),last=R;

        return ans;
    }
};