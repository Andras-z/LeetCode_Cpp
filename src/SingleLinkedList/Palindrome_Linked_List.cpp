// https://leetcode.com/problems/palindrome-linked-list/
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

// 反转链表，顺序遍历原链表和反转链表并比较值是否相等
static bool isPal(ListNode *head)
{
    ListNode *cur, *pre;
    pre = nullptr;
    cur = head;

    // 创建新的反转链表
    while (cur != nullptr) {
        ListNode *node = new ListNode(cur->val);
        node->next = pre;
        pre = node;
        cur = cur->next;
    }

    // 比较原链表与反转链表的值，cur指向原表头，pre指向反转链表表头
    cur = head;
    while (cur != nullptr) {
        if (cur->val != pre->val) {
            return false;
        }
        cur = cur->next;
        pre = pre->next;
    }

    return true;
}

static ListNode *g_left = nullptr;

static bool traverse(ListNode *right)
{
    if (right == nullptr) {
        return true;
    }

    bool res = traverse(right->next);
    // 后序遍历
    res = res && (right->val == g_left->val);
    g_left = g_left->next;
    return res;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 如果fast指针没有指向null，说明链表长度为奇数，slow还要再前进一步
        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode *left = head;
        ListNode *right = reverse(slow, nullptr);
        while (right != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }

    ListNode *reverse(ListNode *a, ListNode *b)
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
    ListNode list1_5(1);
    ListNode list1_4(2, &list1_5);
    ListNode list1_3(3, &list1_4);
    ListNode list1_2(2, &list1_3);
    ListNode list1(1, &list1_2);

    show(&list1);

    Solution res;

    bool ans = res.isPalindrome(&list1);

    cout << "Palindrome Linked List. isPalindrome: " << ans << endl;

    return 1;
}