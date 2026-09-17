class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int completeDay = 0;
        int i = 0;
        while (i < hours.size() - 1) {
            int j = i + 1;
            while (j < hours.size())
                if ((hours[i] + hours[j++]) % 24 == 0)
                    completeDay += 1;

            i++;
        }
        return completeDay;
    }
};