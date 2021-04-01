//
// Created by yuanh on 2021/4/1.
//

#ifndef LEETCODE_LINK_LIST_H
#define LEETCODE_LINK_LIST_H


#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class LinkList
{
public:
    static ListNode* CreatListEndInsert(vector<int> elements)
    {
        ListNode dummy_node = ListNode(0, nullptr);
        ListNode* end = &dummy_node;
        for (auto element : elements)
        {
            auto tmp_node = new ListNode(element, nullptr);
            end->next = tmp_node;
            end = tmp_node;
        }
        return dummy_node.next;
    }

    static void PrintListNode(ListNode *head)
    {
        while (head!= nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }

    static int GetListLength(ListNode* head)
    {
        if (head == nullptr)
            return 0;
        int length = 0;
        while (head != nullptr)
        {
            head = head->next;
            length++;
        }
        return length;
    }

    static ListNode* StepForward(ListNode* head, int step)
    {
        while (head!= nullptr && step>0)
        {
            head = head->next;
            step--;
        }
        return head;
    }

    static ListNode* FindIntersection(ListNode *headA, ListNode *headB)
    {
        while (headA!= nullptr && headB!= nullptr)
        {
            if (headA == headB)
            {
                break;
            } else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        if (headA != nullptr && headB!= nullptr)
            return headA;
        else
            return nullptr;
    }

    static ListNode *GetIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* intersection_node;
        int len_A;
        int len_B;

        len_A = GetListLength(headA);
        len_B = GetListLength(headB);

        int difference = abs((len_A - len_B));

        if (difference > 0)
        {
            if (len_A > len_B)
            {
                headA = StepForward(headA, difference);
                intersection_node = FindIntersection(headA, headB);
            } else
            {
                headB = StepForward(headB, difference);
                intersection_node = FindIntersection(headA, headB);
            }
        } else
        {
            intersection_node = FindIntersection(headA, headB);
        }

        return intersection_node;

    }

    static ListNode* GetIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *p_A = headA, *p_B = headB;

        while (p_A != p_B)
        {
            p_A = p_A ? p_A->next : headB;
            p_B = p_B ? p_B->next : headA;
        }

        if (p_A!= nullptr && p_B!= nullptr)
            return p_A;
        else
            return nullptr;

    }

    static ListNode* ReverseListIteration(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *current = head, *pre = nullptr;
        while (current!= nullptr)
        {
            ListNode *tmp_node = current->next;
            current->next = pre;
            pre = current;
            current = tmp_node;
        }
        return pre;
    }

    static ListNode* ReverseListRecursion(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *new_head = ReverseListIteration(head->next);

        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }



};


#endif //LEETCODE_LINK_LIST_H
