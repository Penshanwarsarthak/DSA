class Solution {
public:
    int maxDepth(string s) {
        int d=0, ans=0;

        for(char c:s) {
            if(c=='(') ans=max(ans,++d);
            else if(c==')') d--;
        }
        return ans;
    }
};