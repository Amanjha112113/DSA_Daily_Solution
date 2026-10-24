class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto dateToDay = [](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };

        int arriveAliceDay = dateToDay(arriveAlice);
        int leaveAliceDay = dateToDay(leaveAlice);
        int arriveBobDay = dateToDay(arriveBob);
        int leaveBobDay = dateToDay(leaveBob);

        int startOverlap = max(arriveAliceDay, arriveBobDay);
        int endOverlap = min(leaveAliceDay, leaveBobDay);

        if (startOverlap <= endOverlap) {
            return endOverlap - startOverlap + 1;
        }
        
        return 0;
    }
};