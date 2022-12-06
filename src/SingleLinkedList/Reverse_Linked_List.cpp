// https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
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
    ListNode list1_5(5);
    ListNode list1_4(4, &list1_5);
    ListNode list1_3(3, &list1_4);
    ListNode list1_2(2, &list1_3);
    ListNode list1(1, &list1_2);

    show(&list1);

    Solution res;

    ListNode* ans = res.reverseList(&list1);

    cout << "Reverse Linked Lists." << endl;

    show(ans);

    return 1;
}