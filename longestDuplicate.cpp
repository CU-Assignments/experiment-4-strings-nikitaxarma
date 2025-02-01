#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 1, right = s.size() - 1, start = -1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            string dup = search(mid, s);
            if (!dup.empty()) {
                start = dup[0];
                result = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    string search(int len, const string& s) {
        unordered_set<string> seen;
        for (int i = 0; i + len <= s.size(); ++i) {
            string sub = s.substr(i, len);
            if (seen.count(sub)) {
                return sub;
            }
            seen.insert(sub);
        }
        return "";
    }
};
