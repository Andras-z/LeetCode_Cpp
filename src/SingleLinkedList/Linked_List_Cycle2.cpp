// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

void show(ListNode *head, int n)
{
    ListNode *p = head;

    cout << "List: [";

    while (p != nullptr && n--) {
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
    ListNode list1_4(4);
    ListNode list1_3(0, &list1_4);
    ListNode list1_2(2, &list1_3);
    ListNode list1(3, &list1_2);
    list1_4.next = &list1_2;

    show(&list1, 4);

    Solution res;

    ListNode* ans = res.detectCycle(&list1);

    cout << "Linked List Cycle II." << endl;

    show(ans, 4);

    return 1;
}