class Solution {
public:
    bool valid(string s) {
        int cnt = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else if(c == ')') {
                if(cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty()) {
            string cur = q.front();
            q.pop();

            if(valid(cur)) {
                ans.push_back(cur);
                found = true;
            }

            if(found) continue;

            for(int i = 0; i < cur.size(); i++) {
                if(cur[i] != '(' && cur[i] != ')') continue;

                string nxt = cur.substr(0, i) + cur.substr(i + 1);

                if(!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};