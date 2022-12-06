// https://leetcode.com/problems/merge-k-sorted-lists/
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
    bool operator < (const ListNode &node) const {
        return val > node.val;
    }
};

struct NodeCmp {
    bool operator() (ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

/*
 * 这个算法是面试常考题，它的时间复杂度是多少呢？
 *
 * 优先队列 pq 中的元素个数最多是 k，所以一次 poll 或者 add 方法的时间复杂度是 O(logk)；
 * 所有的链表节点都会被加入和弹出 pq，所以算法整体的时间复杂度是 O(Nlogk)，其中 k 是链表的条数，N 是这些链表的节点总数。
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode *>, NodeCmp> q;
        ListNode *dummy = new ListNode(-1), *p = dummy;

        for (auto node : lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            ListNode *tmpNode = q.top();
            q.pop();
            p->next = tmpNode;
            if (tmpNode->next != nullptr) {
                q.push(tmpNode->next);
            }
            p = p->next;
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
    ListNode list1_3(5);
    ListNode list1_2(4, &list1_3);
    ListNode list1(1, &list1_2);

    ListNode list2_3(4);
    ListNode list2_2(3, &list2_3);
    ListNode list2(1, &list2_2);

    ListNode list3_2(6);
    ListNode list3(2, &list3_2);

    vector<ListNode*> lists;
    lists.push_back(&list1);
    lists.push_back(&list2);
    lists.push_back(&list3);

    show(&list1);
    show(&list2);
    show(&list3);

    Solution res;

    ListNode* ans = res.mergeKLists(lists);

    cout << "Merge K Sorted Lists." << endl;

    show(ans);

    return 1;
}