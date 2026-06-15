class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            return nullptr;
        }
        
        vector<ListNode*> nodes;
        for (ListNode* p = head; p; p = p->next) {
            nodes.push_back(p);
        }

        int n = nodes.size();
        int mid = n / 2;
        nodes[mid - 1]->next = (mid + 1 < n ? nodes[mid + 1] : nullptr);

        return head;
    }
};