class Solution {
public:
    std::vector<int> bestCoordinate(std::vector<std::vector<int>>& towers, int radius) {
        const int max_radius = 50;
        std::vector<int> result{0, 0};
        int max_q = 0;
        for (int i = 0; i <= max_radius; i++) {
            for (int j = 0; j <= max_radius; j++) {
                int curr_q = 0;
                for (std::vector<int>& tower : towers) {
                    const int tx = tower[0], ty = tower[1];
                    const float dist = std::sqrt(std::pow(i - tx, 2) + std::pow(j - ty, 2));
                    if (dist > radius) continue;
                    curr_q += std::floor(tower[2] / (1 + dist));
                }
                if (curr_q > max_q) {
                    max_q = curr_q;
                    result = {i, j};
                }
            }
        }
        return result;
    }
};