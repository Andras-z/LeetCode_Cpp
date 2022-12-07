#include "common.h"

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        prettyPrintLinkedList(head);
    }
    return 0;
}