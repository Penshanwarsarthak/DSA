class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int target=accumulate(a.begin(),a.end(),0)-x;
        if(target<0) return -1;

        int l=0,sum=0,best=-1;

        for(int r=0;r<a.size();r++){
            sum+=a[r];

            while(sum>target)
                sum-=a[l++];

            if(sum==target)
                best=max(best,r-l+1);
        }

        return best==-1 ? -1 : a.size()-best;
    }
};