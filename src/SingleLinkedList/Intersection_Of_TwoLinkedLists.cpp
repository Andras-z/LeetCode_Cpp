// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            if (p == nullptr) {
                p = headB;
            } else {
                p = p->next;
            }

            if (q == nullptr) {
                q = headA;
            } else {
                q = q->next;
            }
        }
        return p;
    }
};

void show(ListNode *head)
{
    ListNode *p = head;

    cout << "List: [";

    while (p != nullptr) {
        cout << p->val;
        p = p->next;
        if (p != nullptr) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main(void)
{
    ListNode list_3(6);
    ListNode list_2(4, &list_3);
    ListNode list_1(2, &list_2);

    ListNode list1_3(1, &list_1);
    ListNode list1_2(9, &list1_3);
    ListNode list1(1, &list1_2);

    ListNode list2(3, &list_1);

    show(&list1);
    show(&list2);

    Solution res;

    ListNode* ans = res.getIntersectionNode(&list1, &list2);

    cout << "Remove Nth Node From End of List." << endl;

    show(ans);

    return 1;
}