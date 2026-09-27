class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        for(int i = 0; i < operations.size(); i++) {
            switch(operations[i][0]) {
                case 'C':
                    if (!score.empty()) score.pop();
                    break;
                case 'D':
                    if (!score.empty()) score.push(score.top() * 2);
                    break;
                case '+':
                    if (score.size() >= 2) {
                        int t = score.top();
                        score.pop();
                        int temp = score.top();
                        score.push(t);
                        score.push(t + temp);
                    }
                    break;
                default:
                    score.push(stoi(operations[i]));
                    break;
            }
        }
        int sum = 0;
        while (!score.empty()) {
            sum += score.top();
            score.pop();
        }
        return sum;
    }
};