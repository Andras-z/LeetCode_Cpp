// https://leetcode.com/problems/reverse-linked-list-ii/
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

ListNode *successor = nullptr;

static ListNode *reverseN(ListNode *head, int n)
{
    if (n == 1) {
        successor = head->next;
        return head;
    }

    ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;
    return last;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
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

    ListNode* ans = res.reverseBetween(&list1, 2, 4);

    cout << "Reverse Linked Lists II. between 2 4" << endl;

    show(ans);

    return 1;
}