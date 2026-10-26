class Solution {
public:
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    vector<int> leftSum(n), rightSum(n);
    
    leftSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        leftSum[i] = leftSum[i - 1] + nums[i];
    }
    
    rightSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightSum[i] = rightSum[i + 1] + nums[i];
    }
    for (int i = 0; i < n; ++i) {
        int left = i > 0 ? i * nums[i] - leftSum[i - 1] : 0;
        int right = i < n - 1 ? rightSum[i + 1] - (n - i - 1) * nums[i] : 0;
        result[i] = left + right;
    }

    return result;
}
};