// https://leetcode.com/problems/reverse-nodes-in-k-group/
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

static ListNode *reverse(ListNode *a, ListNode *b)
{
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = a;
    nxt = a;

    while (cur != b) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a, *b;
        a = head;
        b = head;

        if (head == nullptr) {
            return nullptr;
        }

        for (int i = 0; i < k; i++) {
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }

        ListNode *newHead = reverse(a, b);

        a->next = reverseKGroup(b, k);

        return newHead;
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

    ListNode* ans = res.reverseKGroup(&list1, 2);

    cout << "Reverse Nodes in K-Group." << endl;

    show(ans);

    return 1;
}