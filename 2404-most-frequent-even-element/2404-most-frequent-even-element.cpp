class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> evenFrequency;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                evenFrequency[num]++;
            }
        }
        int mostFrequentEvenNumber = -1;
        int maxFrequency = 0;

        for (const auto &[evenNum, frequency] : evenFrequency)
        {
            if (frequency > maxFrequency)
            {
                maxFrequency = frequency;
                mostFrequentEvenNumber = evenNum;
            }
            else if (frequency == maxFrequency)
            {
                mostFrequentEvenNumber = min(mostFrequentEvenNumber, evenNum);
            }
        }

        return mostFrequentEvenNumber;
    }
};