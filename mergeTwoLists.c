#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *r = head;
    struct ListNode *p;
    struct ListNode *ret;
    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }
    while (l1 && l2) {
        if(l1->val < l2->val) {
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = l1->val;
            r->next = p;            
            r = p;
            l1 = l1->next;
        } else {
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = l2->val;
            r->next = p;            
            r = p;
            l2 = l2->next;
        }
    }
    while (l1) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = l1->val;
        r->next = p;            
        r = p;
        l1 = l1->next;
    }
    while (l2) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = l2->val;
        r->next = p;            
        r = p;
        l2 = l2->next;
    }
    r->next = NULL;
    ret = head->next;
    free(head);
    return ret;
}