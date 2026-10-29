class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        long long M = 1000000000 + 7;
        vector<long long> first_time_to_reach(n, 0);
        vector<long long> prefix_sum_time_to_come_back(n + 1, 0);
        prefix_sum_time_to_come_back[1] = 1;
        for(int i = 1; i < n; ++i) {
            first_time_to_reach[i] = (first_time_to_reach[i - 1] + prefix_sum_time_to_come_back[i] - prefix_sum_time_to_come_back[i - 1] + 1 + M) % M;
            prefix_sum_time_to_come_back[i + 1] = (prefix_sum_time_to_come_back[i] + 1 + prefix_sum_time_to_come_back[i] - prefix_sum_time_to_come_back[nextVisit[i]] + i - nextVisit[i] + M) % M;
        }
        return first_time_to_reach.back();
    }
};