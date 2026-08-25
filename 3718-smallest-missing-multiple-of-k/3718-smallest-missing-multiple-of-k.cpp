class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }
        for (int i = 1; ; i++) {

            int x = i * k;

            if (st.find(x) == st.end()) {
                return x;
            }
        }
    }
};