class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        long long ans=0, cost=0;
        int j=nums.size()-1;

        for(int i=j;i>=0;i--) {
            int cnt=1;

            while(!dq.empty() && dq.back().first<nums[i]) {
                cost+=1LL*(nums[i]-dq.back().first)*dq.back().second;
                cnt+=dq.back().second;
                dq.pop_back();
            }

            dq.push_back({nums[i],cnt});

            while(cost>k) {
                cost-=dq.front().first-nums[j--];
                if(--dq.front().second==0) dq.pop_front();
            }

            ans+=j-i+1;
        }

        return ans;
    }
};
