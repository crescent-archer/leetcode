// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
#include <iostream>
#include <assert.h>


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{        
    ListNode* front = head;
    ListNode* rear = head;

    for(int i = 0; i < n; ++i)
    {
        rear = rear->next;
    }

    if(!rear)
    {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    
    while(rear->next)
    {
        front = front->next;
        rear = rear->next;
    }

    if(front)
    {
        ListNode* tmp = front->next;
        if(tmp)
        {
            front->next = tmp->next;
            delete tmp;
        }
    }
    
    return head;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

