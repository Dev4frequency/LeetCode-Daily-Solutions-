class Solution {
public:
    int encrypt(int x) {
        string numStr = to_string(x);
        char maxDigit = *max_element(numStr.begin(), numStr.end());
        int encrypted = 0;
        for (char c : numStr) {
            encrypted = encrypted * 10 + (maxDigit - '0');
        }
        return encrypted;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += encrypt(num);
        }
        return sum;
    }
};