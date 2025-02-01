#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq_map;
        for (char task : tasks) {
            freq_map[task]++;
        }
        
        priority_queue<int> max_heap;
        for (auto& entry : freq_map) {
            max_heap.push(entry.second);
        }
        
        int intervals = 0;
        while (!max_heap.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            
            while (cycle > 0 && !max_heap.empty()) {
                int task_count = max_heap.top();
                max_heap.pop();
                if (--task_count > 0) {
                    temp.push_back(task_count);
                }
                cycle--;
            }
            
            for (int task : temp) {
                max_heap.push(task);
            }
            
            intervals += max_heap.empty() ? cycle : n + 1;
        }
        
        return intervals;
    }
};
