// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int flag = 0;
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while(l1 != NULL && l2 != NULL)
    {
        ListNode *p = new ListNode((l1->val + l2->val + flag) % 10);
        flag = (l1->val + l2->val + flag) / 10;
        l1 = l1->next;
        l2 = l2->next;
        cur -> next = p;
        cur = cur -> next;
    }
    
    ListNode *l = l1 != NULL ? l1 : l2;
    
    while(l != NULL)
    {
        ListNode *p = new ListNode((l->val + flag) % 10);
        flag = (l->val + flag) / 10;
        l = l -> next;
        cur -> next = p;
        cur = cur -> next;
    }

    if(flag)
    {
        ListNode *p = new ListNode(1);
        cur-> next = p;
        cur = cur -> next;
    }

    cur -> next = NULL;
    cur = head;
    head = head->next;
    delete cur;

    return head;
}

// 官方解法，计算时将NULL指针当作0处理
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)
{
    int flag = 0;
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while(l1 != NULL || l2 != NULL)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        ListNode *p = new ListNode((x + y + flag) % 10);
        flag = (x + y + flag) / 10;
        l1 = l1 ? l1->next : l1;    // l1比l2短
        l2 = l2 ? l2->next : l2;    // l2比l1短
        cur -> next = p;
        cur = cur -> next;
    }
    
    if(flag)
    {
        ListNode *p = new ListNode(1);
        cur-> next = p;
        cur = cur -> next;
    }

    cur -> next = NULL;
    cur = head;
    head = head->next;
    delete cur;

    return head;
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = NULL;

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = NULL;

    ListNode *p = addTwoNumbers(l1, l2);
    while(p != NULL)
    {
        if(p->next != NULL)
        {
            std::cout << p->val << "->";
        }
        else
        {
            std::cout << p->val << std::endl;
        }
        p = p->next;
    }

    return 0;
}

