class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (auto& query : queries) {
            int i = 0, j = 0;
            while (i < query.size() && j < pattern.size()) {
                if (query[i] == pattern[j]) {
                    i++;
                    j++;
                } else if (islower(query[i])) {
                    i++;
                } else {
                    break;
                }
            }
            result.push_back(j == pattern.size() && all_of(query.begin() + i, query.end(), ::islower));
        }
        return result;
    }
};
