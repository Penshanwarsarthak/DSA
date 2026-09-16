class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long M=1e9+7;
        long long ans=1;

        for(int i=1;i<=2*k;i++)
            ans=ans*(n+k-i)%M;

        for(int i=1;i<=2*k;i++)
            ans=ans*powmod(i,M-2,M)%M;

        return ans;
    }

    long long powmod(long long a,long long b,long long m) {
        long long r=1;
        while(b) {
            if(b&1) r=r*a%m;
            a=a*a%m;
            b>>=1;
        }
        return r;
    }
};