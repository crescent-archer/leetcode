#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
    if(head && head->next)
    {
        head = head->next;
        
        ListNode *front = nullptr;  // first的前一个指针
        ListNode *first = head;     //
        ListNode *second = head->next;
        // 1->2->3->4
        while(first && second)
        {
            first->next = second->next;     // 1->3->4   2->3   1
            second->next = first;           // 2->1->3->4       2

            if(front)   // fisrt不是头节点的情况
            {
                front->next = second;
            }

            front = first;

            first = first->next;            // 3
            if(!first)
            {
                break;
            }
            second = first->next;           // 4
        }
    }

    return head;
}

int main()
{
    return 0;
}

