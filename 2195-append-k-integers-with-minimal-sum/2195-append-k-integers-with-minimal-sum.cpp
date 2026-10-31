class Solution {
public:
    long long minimalKSum(vector<int>& numbers, int k) {
        sort(numbers.begin(), numbers.end());
        long long totalSum = 0;
        int size = numbers.size();
        
        for (int idx = 0; idx < size && k > 0; ++idx) {
            long long previousNum = (idx == 0) ? 0 : numbers[idx - 1];
            long long countToAdd = min((long long)k, max((long long)0, numbers[idx] - previousNum - 1));
            k -= countToAdd;
            totalSum += (previousNum + 1 + previousNum + countToAdd) * countToAdd / 2;
        }
        
        if (k > 0) {
            totalSum += ((long long)numbers.back() + 1 + numbers.back() + k) * k / 2;
        }
        
        return totalSum;
    }
};