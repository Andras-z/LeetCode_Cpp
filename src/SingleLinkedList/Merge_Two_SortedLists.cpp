// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = list1, *p2 = list2;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }

        if (p2 != nullptr) {
            p->next = p2;
        }

        return dummy->next;
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
    ListNode list1_3(3);
    ListNode list1_2(2, &list1_3);
    ListNode list1(1, &list1_2);

    ListNode* list2_3 = new ListNode(4);
    ListNode* list2_2 = new ListNode(3, list2_3);
    ListNode* list2 = new ListNode(1, list2_2);

    show(&list1);
    show(list2);

    Solution res;

    ListNode* ans = res.mergeTwoLists(&list1, list2);

    cout << "Merge Two Sorted Lists." << endl;

    show(ans);

    return 1;
}