#include <iostream>
#include "link_list.h"

int main()
{
    LinkList link_list;
    vector<int> list_elements{1, 2, 3, 4, 5};
    ListNode* lists = link_list.CreatListEndInsert(list_elements);
    link_list.PrintListNode(lists);
    ListNode* reverse_lists = link_list.ReverseListRecursion(lists);
    link_list.PrintListNode(reverse_lists);
    return 0;
}







