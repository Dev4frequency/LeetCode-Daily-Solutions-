class Solution {
public:
    vector<int> convertLLToArray(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        return arr;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> cArr = convertLLToArray(head);
        int n = cArr.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && cArr[i] > cArr[st.top()]) {
                ans[st.top()] = cArr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};