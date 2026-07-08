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
    //insert a new node at the end of the answer linked list
    void insertAtTail(ListNode*& head, ListNode*& tail, int data) {
        ListNode* temp = new ListNode(data);

        if (head == NULL) {
            head = temp;
            tail = temp;
        } 

        else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        //T.C = O(max(N, M)) where N and M are the lengths of l1 and l2
        //S.C = O(max(N, M)) new linked list is created to store the result

        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;     

            int dig = sum % 10;

            insertAtTail(ansHead, ansTail, dig);//append the digit to the result list

            carry = sum / 10; //update carry

            //move to the next nodes if available
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return ansHead;

    }
};
