class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;

        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] >= itemSize) {
                if (ans == -1 || capacity[i] < capacity[ans]) {
                    ans = i;
                }
            }
        }

        return ans;
    }
};