// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fNode = dummy, *sNode = dummy;
        int cnt = 0;

        while (fNode != nullptr && cnt <= n) {
            fNode = fNode->next;
            cnt++;
        }

        while (fNode != nullptr) {
            fNode = fNode->next;
            sNode = sNode->next;
        }

        sNode->next = sNode->next->next;

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
    ListNode list1_6(6);
    ListNode list1_5(5, &list1_6);
    ListNode list1_4(4, &list1_5);
    ListNode list1_3(3, &list1_4);
    ListNode list1_2(2, &list1_3);
    ListNode list1(1, &list1_2);

    show(&list1);

    Solution res;

    ListNode* ans = res.removeNthFromEnd(&list1, 1);

    cout << "Remove Nth Node From End of List." << endl;

    show(ans);

    return 1;
}