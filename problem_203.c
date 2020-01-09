#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// *  * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void Init(struct ListNode **pHead, int *arr, int iSize)
{
    if (iSize == 0)
    {
        return;
    }
    (*pHead) = (struct ListNode *)malloc(sizeof(struct ListNode));
    assert((*pHead) != NULL);
    memset(*pHead, 0, sizeof(struct ListNode));
    (*pHead)->val = arr[0];
    (*pHead)->next = NULL;
    struct ListNode *p = (*pHead);
    for (int i = 1; i < iSize; ++i)
    {
        struct ListNode *pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        assert(pNode != NULL);
        pNode->next = p->next;
        pNode->val = arr[i];
        p->next = pNode;
        p = pNode;
    }
}

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    
    while (head != NULL && head->val == val)    
    {
        head = head->next;
    }
    if (head == NULL)
    {
        return head;
    }
    struct ListNode *pPre = head;
    struct ListNode *p = head->next;
    while (p != NULL)
    {
        if (p->val == val)
        {
            pPre->next = p->next;
            struct ListNode *q = p;
            p = p->next;
            free(q);
        }
        else
        {
            pPre = p;
            p = p->next;
        }
    }
    return head;
}

void PrintList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d,", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,6,3,4,5,6};
    int iSize = sizeof(arr) / sizeof(int);
    struct ListNode *head = NULL;
    Init(&head, arr, iSize);
    PrintList(head);
    int iVal = 6;
    struct ListNode *pRet = removeElements(head, iVal);
    PrintList(pRet);
    return 0;
}
