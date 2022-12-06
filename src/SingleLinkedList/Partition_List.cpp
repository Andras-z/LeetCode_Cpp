// https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = head;
        ListNode *dummy1 = new ListNode(-1), *l = dummy1;
        ListNode *dummy2 = new ListNode(-1), *g = dummy2;

        while (p != nullptr) {
            if (p->val < x) {
                l->next = p;
                l = l->next;
            } else {
                g->next = p;
                g = g->next;
            }
            p = p->next;
        }

        g->next = nullptr;
        l->next = dummy2->next;

        return dummy1->next;
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
    ListNode list1_6(2);
    ListNode list1_5(5, &list1_6);
    ListNode list1_4(2, &list1_5);
    ListNode list1_3(3, &list1_4);
    ListNode list1_2(4, &list1_3);
    ListNode list1(1, &list1_2);

    show(&list1);

    Solution res;

    ListNode* ans = res.partition(&list1, 3);

    cout << "Partition List." << endl;

    show(ans);

    return 1;
}