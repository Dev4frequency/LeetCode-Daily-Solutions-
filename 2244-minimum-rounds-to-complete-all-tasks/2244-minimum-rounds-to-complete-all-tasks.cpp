#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        map<int, int> freq;
        for (int t : tasks) {
            freq[t]++;
        }
        
        int rounds = 0;
        for (auto [task, count] : freq) {
            if (count == 1) return -1;
            
            rounds += (count + 2) / 3;
        }
        return rounds;
    }
};