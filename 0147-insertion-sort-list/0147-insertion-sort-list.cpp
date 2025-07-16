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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); // Dummy node
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;
            // Find the right spot in the sorted part
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            ListNode* nextTemp = curr->next;
            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextTemp;
        }

        return dummy->next;
    }
};