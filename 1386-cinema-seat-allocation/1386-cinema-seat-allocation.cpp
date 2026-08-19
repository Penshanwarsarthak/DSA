class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> mp;

        for (auto seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row].insert(col);
        }

        int ans = 0;

        int emptyRows = n - mp.size();

        ans += emptyRows * 2;

        for (auto &row : mp) {

            set<int>& seats = row.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                    break;
                }
            }

            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            }

            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};