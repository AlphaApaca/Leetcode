#include <stdio.h>
#include <stdlib.h>
#include "utils/linkedlist.h" // 引入自定义数据结构

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}

int main() {
    // 本地测试用例
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    int len1 = sizeof(a)/sizeof(a[0]);
    int len2 = sizeof(b)/sizeof(b[0]);
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    for (int i = len1 - 1; i >= 0; i--) {
        l1 = insertAtHead(l1, a[i]);
    }
    for (int i = len2 - 1; i >= 0; i--) {
        l2 = insertAtHead(l2, b[i]);
    }
    struct ListNode* result = addTwoNumbers(l1, l2);
    traverseList(result);
    // 输出结果：7 -> 0 -> 8
    freeList(l1);
    freeList(l2);
    freeList(result);
    return 0;
}