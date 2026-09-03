class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                ans.push_back(i);
            }
        }
        int count = 0;
        for (int i : ans) {
            if (i + count < arr.size()) {
                arr.insert(arr.begin() + i + count, 0);
                arr.pop_back();
                count++;
            }
        }
    }
};