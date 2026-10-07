class Solution {
    bool isValid(const string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                ++balance;
            } else if (c == ')' && --balance < 0) {
                return false;
            }
        }

        return balance == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> level{s};

        while (true) {
            vector<string> answer;
            for (const string& candidate : level) {
                if (isValid(candidate)) {
                    answer.push_back(candidate);
                }
            }
            if (!answer.empty()) {
                return answer;
            }
            unordered_set<string> nextLevel;

            for (const string& candidate : level) {
                for (int i = 0; i < static_cast<int>(candidate.size()); ++i) {
                    if (candidate[i] != '(' && candidate[i] != ')') {
                        continue;
                    }
                    if (i > 0 && candidate[i] == candidate[i - 1]) {
                        continue;
                    }

                    nextLevel.insert(
                        candidate.substr(0, i) + candidate.substr(i + 1)
                    );
                }
            }

            level = std::move(nextLevel);
        }
    }
};