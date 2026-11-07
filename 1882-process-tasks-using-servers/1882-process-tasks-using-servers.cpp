class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using P = pair<int,int>;
        using T = tuple<long long,int,int>;

        priority_queue<P,vector<P>,greater<P>> idle;
        priority_queue<T,vector<T>,greater<T>> busy;

        for(int i=0;i<servers.size();i++)
            idle.push({servers[i],i});

        vector<int> ans(tasks.size());
        long long time=0;

        for(int i=0;i<tasks.size();i++) {
            time=max(time,(long long)i);

            while(!busy.empty() && get<0>(busy.top())<=time) {
                auto [t,w,id]=busy.top();
                busy.pop();
                idle.push({w,id});
            }

            if(idle.empty()) {
                time=get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top())<=time) {
                    auto [t,w,id]=busy.top();
                    busy.pop();
                    idle.push({w,id});
                }
            }

            auto [w,id]=idle.top();
            idle.pop();

            ans[i]=id;
            busy.push({time+tasks[i],w,id});
        }

        return ans;
    }
};