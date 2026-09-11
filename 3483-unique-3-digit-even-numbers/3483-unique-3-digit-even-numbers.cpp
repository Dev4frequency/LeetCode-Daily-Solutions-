class Solution {
public: 
    int totalNumbers(vector<int>& digits) {
        array<int, 10> freqMap = {0};
        bool hasEven = false;
        for(int num : digits){
            freqMap[num] += (freqMap[num] < 3);
            hasEven |= (num % 2 == 0);
        }
        if (!hasEven) return 0;
        int totalCount = 0;
        for(int firstDigit = 1; firstDigit < 10; firstDigit++){
            if (freqMap[firstDigit] == 0) continue;
            freqMap[firstDigit]--;
            for(int secondDigit = 0; secondDigit < 10; secondDigit++){
                if (freqMap[secondDigit] == 0) continue;
                freqMap[secondDigit]--;
                for(int lastDigit = 0; lastDigit < 10; lastDigit += 2){
                    if (freqMap[lastDigit] == 0) continue;
                    totalCount++;
                }
                freqMap[secondDigit]++;
            }
            freqMap[firstDigit]++;
        }
        return totalCount;
    }
};