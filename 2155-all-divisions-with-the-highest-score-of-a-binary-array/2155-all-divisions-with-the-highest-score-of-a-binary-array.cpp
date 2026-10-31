#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& inputArray) {
        int totalLength = inputArray.size();
        vector<int> zeroCount(totalLength + 1, 0), oneCount(totalLength + 1, 0);
        
        for (int i = 1; i <= totalLength; ++i) {
            zeroCount[i] = zeroCount[i - 1] + (inputArray[i - 1] == 0);
        }
        
        for (int j = totalLength - 1; j >= 0; --j) {
            oneCount[j] = oneCount[j + 1] + (inputArray[j] == 1);
        }
        
        int highestScore = 0;
        vector<int> optimalIndices;
        
        for (int k = 0; k <= totalLength; ++k) {
            int currentScore = zeroCount[k] + oneCount[k];
            if (currentScore > highestScore) {
                highestScore = currentScore;
                optimalIndices = {k};
            } else if (currentScore == highestScore) {
                optimalIndices.push_back(k);
            }
        }
        
        return optimalIndices;
    }
};