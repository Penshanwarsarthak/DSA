class Solution {
    struct Node {
        int p=1, c[5]={};
    };

    int n,k;
    vector<Node> t;

    Node merge(Node a,Node b) {
        Node r;
        r.p=a.p*b.p%k;

        for(int i=0;i<k;i++) {
            r.c[i]+=a.c[i];
            r.c[a.p*i%k]+=b.c[i];
        }
        return r;
    }

    void build(int p,int l,int r,vector<int>& a) {
        if(l==r) {
            t[p].p=a[l]%k;
            t[p].c[t[p].p]=1;
            return;
        }
        int m=(l+r)/2;
        build(p*2,l,m,a);
        build(p*2+1,m+1,r,a);
        t[p]=merge(t[p*2],t[p*2+1]);
    }

    void update(int p,int l,int r,int i,int x) {
        if(l==r) {
            t[p]=Node();
            t[p].p=x%k;
            t[p].c[t[p].p]=1;
            return;
        }
        int m=(l+r)/2;
        if(i<=m) update(p*2,l,m,i,x);
        else update(p*2+1,m+1,r,i,x);
        t[p]=merge(t[p*2],t[p*2+1]);
    }

    Node query(int p,int l,int r,int L,int R) {
        if(L<=l && r<=R) return t[p];

        int m=(l+r)/2;
        if(R<=m) return query(p*2,l,m,L,R);
        if(L>m) return query(p*2+1,m+1,r,L,R);

        return merge(query(p*2,l,m,L,R),
                     query(p*2+1,m+1,r,L,R));
    }

public:
    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        k=K;
        n=nums.size();
        t.resize(4*n);

        build(1,0,n-1,nums);

        vector<int> ans;

        for(auto &q:queries) {
            update(1,0,n-1,q[0],q[1]);
            ans.push_back(query(1,0,n-1,q[2],n-1).c[q[3]]);
        }

        return ans;
    }
};