class Solution {
public:
    int countSwapsToTarget(string original, string target) {
        int n = original.size();
        int swaps = 0;
        
        for (int i = 0; i < n; i++) {
            if (original[i] != target[i]) {
                int j = i;
                while (original[j] != target[i]) {
                    j++;
                }
                while (j > i) {
                    swap(original[j], original[j - 1]);
                    swaps++;
                    j--;
                }
            }
        }
        return swaps;
    }
    
    int getMinSwaps(string num, int k) {
        string original = num;
        while (k--) {
            next_permutation(num.begin(), num.end());
        }
        return countSwapsToTarget(original, num);
    }
};