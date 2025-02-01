#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, int> last_completed;
        int days = 0;

        for (int task : tasks) {
            days++;
            if (last_completed.find(task) != last_completed.end()) {
                int last_day = last_completed[task];
                if (days - last_day <= space) {
                    days = last_day + space + 1;
                }
            }
            last_completed[task] = days;
        }

        return days;
    }
};
