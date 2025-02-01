#include <unordered_map>
#include <sstream>
#include <vector>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        unordered_map<char, string> patternMap;
        unordered_map<string, char> wordMap;
        
        for (int i = 0; i < pattern.size(); ++i) {
            char pChar = pattern[i];
            string w = words[i];
            
            if (patternMap.count(pChar)) {
                if (patternMap[pChar] != w) {
                    return false;
                }
            } else {
                patternMap[pChar] = w;
            }
            
            if (wordMap.count(w)) {
                if (wordMap[w] != pChar) {
                    return false;
                }
            } else {
                wordMap[w] = pChar;
            }
        }
        
        return true;
    }
};
