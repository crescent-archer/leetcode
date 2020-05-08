// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(nullptr == l1 || nullptr == l2)
    {
        return l1 ? l1 : l2;
    }

    if(l1->val > l2->val)
    {
        return mergeTwoLists(l2, l1);
    }

    ListNode* head = l1;
    ListNode* cur;
    while(l1 && l2)
    {
        while(l1->next && l1->next->val <= l2->val)
        {
            l1 = l1->next;
        }

        cur = l1;
        l1 = l1->next;
        cur->next = l2;
        
        if(!l1)
        {
            break;
        }

        while(l2->next && l2->next->val <= l1->val)
        {
            l2 = l2->next;
        }
        cur = l2;
        l2 = l2->next;
        cur->next = l1;
    }

    if(l1)
    {
        cur->next = l1;
    }
    else
    {
        cur->next = l2;
    }

    return head;
}

int main()
{
    ListNode* l1 = new ListNode(-9);
    l1->next = new ListNode(3);
    l1->next->next = nullptr;
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(7);
    l2->next->next = nullptr;

    ListNode* head = mergeTwoLists(l1, l2);
    while(head)
    {
        std::cout << head->val << " ";
    }
    std::cout << std::endl;
    return 0;
}

