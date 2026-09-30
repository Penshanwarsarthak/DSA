class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans;
        int d=0;

        for(char c:s) {
            if(c=='(') ans.push_back(d++%2);
            else ans.push_back(--d%2);
        }

        return ans;
    }
};