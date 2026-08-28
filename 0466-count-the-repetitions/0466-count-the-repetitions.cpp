class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;

        unordered_map<int, pair<int, int>> seen;
        int s1_count = 0, s2_count = 0, index = 0;

        while (s1_count < n1) {
            for (char c : s1) {
                if (c == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        s2_count++;
                        index = 0;
                    }
                }
            }
            s1_count++;

            if (seen.find(index) != seen.end()) {
                auto [prev_s1_count, prev_s2_count] = seen[index];
                int cycle_length = s1_count - prev_s1_count;
                int cycle_s2_count = s2_count - prev_s2_count;

                int remaining_cycles = (n1 - s1_count) / cycle_length;
                s1_count += remaining_cycles * cycle_length;
                s2_count += remaining_cycles * cycle_s2_count;
            }

            seen[index] = {s1_count, s2_count};
        }

        return s2_count / n2;
    }
};