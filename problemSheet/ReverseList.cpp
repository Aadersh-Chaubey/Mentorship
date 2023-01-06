// https://leetcode.com/problems/reverse-linked-list/submissions/872653301/
// TC= O(n)
// SC= O(1)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* dm = new ListNode(-1, NULL), *curr;
        dm->next = curr = head;
        while(curr != NULL && curr->next != NULL){
            ListNode* t = curr->next->next;
            curr->next->next = dm->next;
            dm->next = curr->next;
            curr->next = t;
        }
        return dm->next;
    }
};