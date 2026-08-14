class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxPrime = 0;

        for (int i = 0; i < n; ++i) {
            int a = nums[i][i];
            int b = nums[i][n - 1 - i];
            if (isPrime(a)) maxPrime = max(maxPrime, a);
            if (isPrime(b)) maxPrime = max(maxPrime, b);
        }

        return maxPrime;
    }
};