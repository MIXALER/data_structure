//
// Created by yuanh on 2021/4/1.
//

#ifndef LEETCODE_LINK_LIST_H
#define LEETCODE_LINK_LIST_H


#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val, ListNode *next) : val(val), next(next)
    {}
};

class LinkList
{
public:
    static ListNode *CreatListEndInsert(vector<int> elements)
    {
        ListNode dummy_node = ListNode(0, nullptr);
        ListNode *end = &dummy_node;
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
        while (head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }

    static int GetListLength(ListNode *head)
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

    static ListNode *StepForward(ListNode *head, int step)
    {
        while (head != nullptr && step > 0)
        {
            head = head->next;
            step--;
        }
        return head;
    }

    static ListNode *FindIntersection(ListNode *headA, ListNode *headB)
    {
        while (headA != nullptr && headB != nullptr)
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
        if (headA != nullptr && headB != nullptr)
            return headA;
        else
            return nullptr;
    }

    static ListNode *GetIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *intersection_node;
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

    static ListNode *GetIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *p_A = headA, *p_B = headB;

        while (p_A != p_B)
        {
            p_A = p_A ? p_A->next : headB;
            p_B = p_B ? p_B->next : headA;
        }

        if (p_A != nullptr && p_B != nullptr)
            return p_A;
        else
            return nullptr;

    }

    static ListNode *ReverseListIteration(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *current = head, *pre = nullptr;
        while (current != nullptr)
        {
            ListNode *tmp_node = current->next;
            current->next = pre;
            pre = current;
            current = tmp_node;
        }
        return pre;
    }

    static ListNode *ReverseListRecursion(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *new_head = ReverseListIteration(head->next);

        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0, nullptr), *current = dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            } else
            {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr)
        {
            current->next = l1;
        }
        if (l2 != nullptr)
        {
            current->next = l2;
        }
        return dummy->next;

    }

    ListNode *mergeTwoLists_recursion(ListNode *l1, ListNode *l2)
    {
        // 递归处理边界情况
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode *deleteDuplicates(ListNode *head)
    {
        //我觉得需要一个字典来存放已经存在的值
//        map<int, int>
        set<int> exist_value;
        ListNode *current = head;
        ListNode *pre = new ListNode(0, nullptr);
        pre->next = current;
        while (current != nullptr)
        {
            if (exist_value.count(current->val))
            {
                pre->next = current->next;
                current = current->next;
            } else
            {
                exist_value.insert(current->val);
                pre = current;
                current = current->next;
            }
        }
        return head;
    }

    ListNode *deleteDuplicates_recursion(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) //这个写法很绝妙啊，如果head为空指针的化，就不用判断对后面进行判断了，判断会出错。
            return head;
        ListNode *tmp_head = deleteDuplicates_recursion(head->next);
        if (head->val == tmp_head->val)
            return tmp_head;
        else
        {
            head->next = tmp_head;
            return head;
        }
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //双指针，前面的指针走n步以后，后面的指针开始走，当前面的指针走到终点时，后面的指针指向倒数第n个节点
        ListNode *next = head, *pre = head;
        while (n > 0)
        {
            next = next->next;
            n--;
        }
        // 这里需要判断next指针是否为空，如果为空，说明倒数第 n 个节点为头节点
        if (next == nullptr)
            return head->next;
        while (next->next != nullptr)
        {
            next = next->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }

    int current;

    ListNode *removeNthFromEnd_Recursion(ListNode *head, int n)
    {
        // 需要一个全局变量来记录位置，就是上面的 current 。
        if (head == nullptr)
            return head;
        head->next = removeNthFromEnd_Recursion(head->next, n);
        current++;
        if (n == current)
            return head->next;
        return head;

    }

    ListNode *swapPairs_Recursion(ListNode *head)
    {
        // 首选递归方式，处理边界条件
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *end = head, *front = head->next->next;
        head = head->next;

        end->next->next = end;
        end->next = swapPairs_Recursion(front);
        return head;
    }

    ListNode *swapPairs_Iteration(ListNode *head)
    {
        // 迭代方式，处理边界条件
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *end = head, *front = head->next->next;
        head = head->next;

        end->next->next = end;
        end->next = swapPairs_Recursion(front);
        return head;
    }


};


#endif //LEETCODE_LINK_LIST_H
