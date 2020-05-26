#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getNextK(ListNode *p, int k)
{
    for(int i = 0; p && i < k - 1; ++i)
    {
        p = p->next;
    }
    return p;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *pre = NULL;
    ListNode *front = head;

    ListNode *tail = getNextK(head, k);
    head = tail ? tail : head;
    while(tail)
    {
        if(pre)
        {
            pre->next = tail;
        }
        pre = front;
        ListNode *front_next = front->next;
        ListNode *tmp;
        while(front != tail)    // 1->2->3->4->5
        {
            tmp = front_next->next;
            front_next->next = front;
            front = front_next;
            front_next = tmp;
        }
        pre->next = tmp;
        front = tmp;
        tail = getNextK(front, k);
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    head = reverseKGroup(head, 2);

    while(head)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }


    return 0;
}

