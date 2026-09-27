class Solution {
public:
    string reverseParentheses(string s) {
        string st;

        for(char c : s) {
            if(c == ')') {
                string t;
                while(st.back() != '(') {
                    t += st.back();
                    st.pop_back();
                }
                st.pop_back();
                st += t;
            } else {
                st += c;
            }
        }
        return st;
    }
};