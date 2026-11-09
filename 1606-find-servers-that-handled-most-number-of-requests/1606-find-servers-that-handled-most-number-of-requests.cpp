class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> idle;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;
        vector<int> cnt(k);

        for(int i=0;i<k;i++) idle.insert(i);

        for(int i=0;i<arrival.size();i++) {
            while(!busy.empty() && busy.top().first<=arrival[i]) {
                idle.insert(busy.top().second);
                busy.pop();
            }

            if(idle.empty()) continue;

            auto it=idle.lower_bound(i%k);
            if(it==idle.end()) it=idle.begin();

            int id=*it;
            idle.erase(it);

            cnt[id]++;
            busy.push({arrival[i]+load[i],id});
        }

        int mx=*max_element(cnt.begin(),cnt.end());
        vector<int> ans;

        for(int i=0;i<k;i++)
            if(cnt[i]==mx) ans.push_back(i);

        return ans;
    }
};