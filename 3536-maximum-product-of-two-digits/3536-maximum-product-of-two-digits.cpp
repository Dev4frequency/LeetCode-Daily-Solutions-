class Solution {
public:
    int maxProduct(int number) {
        int first = -1, second = -1;

        for (; number > 0; number /= 10) {
            int digit = number % 10;

            if (digit > first) {
                second = first;
                first = digit;
            } else if (digit > second) {
                second = digit;
            }
        }

        return first * second;
    }
};
