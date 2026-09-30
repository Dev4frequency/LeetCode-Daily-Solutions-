class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ger(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(arr[i]);
                ger[i] = -1;
            }
            else if (arr[i] > st.top()) {
                ger[i] = st.top();
                st.push(arr[i]);
            }
            else {
                ger[i] = st.top();
            }
        }

        return ger;
    }
};