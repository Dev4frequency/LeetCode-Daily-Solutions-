class Solution {
public:
    int countBalls(int lowLimit, int highLimit) 
    {
        vector<int> count(46, 0);
        int result = 0;

        for (int num = lowLimit; num <= highLimit; ++num) 
        {
            int sum = 0, x = num;
            while (x > 0) 
            {
                sum += x % 10;
                x /= 10;
            }
            result = max(result, ++count[sum]);
        }

        return result;
    }
};