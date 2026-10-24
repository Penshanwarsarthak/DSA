class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int days[] = {0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));

            for (int i = 1; i < m; i++)
                d += days[i];

            return d;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};