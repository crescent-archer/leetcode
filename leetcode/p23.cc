//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
#include <iostream>
#include <vector>

using std::vector;

//Definition for singly-linked list.
struct ListNode 
{
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

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if(lists.size() == 1)
    {
        return lists[0];
    }
    if(lists.empty())
    {
        return {};
    }

    ListNode* head = lists[0];
    for(size_t i = 1; i < lists.size(); ++i)
    {
        head = mergeTwoLists(head, lists[i]); 
    }

    return head;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

