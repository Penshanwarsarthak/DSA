class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int d=0;

        for(char c:s) {
            if(c=='(') {
                if(d++) ans+=c;
            } else {
                if(--d) ans+=c;
            }
        }
        return ans;
    }
};