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

bool isPalindrome(struct ListNode* head) 
{ 
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    while (pSlow->next != NULL && pFast->next->next != NULL)
    {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pFast->next == NULL)
        {
            break;
        }
    }
    struct ListNode *pPre = pSlow;
    struct ListNode *p = pSlow->next;
    while (p != NULL)
    {
        struct ListNode *q = p->next;
        p->next = pPre;
        pPre = p;
        p = q;
    }
    pSlow->next = NULL;
    struct ListNode *pStart = head;
    struct ListNode *pEnd = pPre;
    
    while (pStart != NULL && pEnd != NULL)
    {
        if (pStart->val != pEnd->val)
        {
            return false;
        }
        pStart = pStart->next;
        pEnd = pEnd->next;
    }
    return true;

}

int main()
{
    int arr[] = {1,0,0};
    int iSize = sizeof(arr) / sizeof(int);
    struct ListNode *head = NULL;
    Init(&head, arr, iSize);
    bool bRet = isPalindrome(head);
    if (bRet)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    };
    return 0;
}
