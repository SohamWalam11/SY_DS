struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *head = NULL, *tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct ListNode *new_node;
        if (list1->val < list2->val) {
            new_node = list1;
            list1 = list1->next;
        } else {
            new_node = list2;
            list2 = list2->next;
        }

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    return head;
}