#include<climits>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr ||head->next->next==nullptr){
            return {-1,-1};
        }
        ListNode* cur;
        int prevVal=head->val;
        int min=INT_MAX;
        int max=-1;
        int min_delta=INT_MAX;
        int i=0;
        for(cur=head->next;cur->next!=nullptr;cur=cur->next)
        {
            if((cur->val>prevVal && cur->val>cur->next->val) ||
            (cur->val<prevVal && cur->val<cur->next->val))
            {
                if(i<min) min=i;
                if(max!=-1 && i-max<min_delta) min_delta=i-max;
                max=i;
                
            }
            i++;
            prevVal=cur->val;
        }
        if(max!=-1 && max!=min)
        {
            return {min_delta,max-min};
        }
        return {-1,-1};
    }
};