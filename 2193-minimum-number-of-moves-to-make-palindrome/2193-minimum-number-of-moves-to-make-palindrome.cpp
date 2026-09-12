class Solution {
public:
    int minMovesToMakePalindrome(string input) {
        int totalMoves = 0;

        while (!input.empty()) {
            char lastCharacter = input.back();
            int position = input.find(lastCharacter);
            if (position == input.size() - 1) {
                totalMoves += position / 2;
            } else {
                totalMoves += position;
                input.erase(position, 1);
            }

            input.pop_back();
        }

        return totalMoves;
    }
};

auto optimizeIO = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();