class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int size = arr.size();  
        vector<int> arr_k;

        while (size > 1) {
            int maxIndex = 0;
            for (int i = 0; i < size; ++i) {
                if (arr[i] == size) {
                    maxIndex = i;
                    break;
                }
            }
            if (maxIndex != size - 1) {
                if (maxIndex != 0) {
                    reverse(arr.begin(), arr.begin() + maxIndex + 1);
                    arr_k.push_back(maxIndex + 1);
                }
                reverse(arr.begin(), arr.begin() + size);
                arr_k.push_back(size);
            }
            size -= 1;
        }

        return arr_k;
    }
};