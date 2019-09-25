/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//之前写的，
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode* middle;

    struct ListNode tempfront;
    tempfront.next = head;
    struct ListNode* front = &tempfront;
    struct ListNode* rear;
    struct ListNode* temp;
    head = front;
    int flag = 1;
    int count = 0;
    while (head != NULL) {
        if (count == k) {
            rear = head;
            temp = front->next;
            head = head->next;
            rear->next = NULL;
            middle = front->next->next;
            front->next->next = head;
            while (middle != NULL) {
                rear = middle;
                middle = middle->next;
                rear->next = front->next;
                front->next = rear;
            }
            count = 0;
            front = temp;
            head = front;
        } else {
            head = head->next;
            count++;
        }
    }
    return tempfront.next;
}
