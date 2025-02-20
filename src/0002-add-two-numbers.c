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

//第一感，很简单啊，从两个链表的头开始相加，有进位存到temp里面加到下一层，
//直到读到两个链表全为null，有进位再把进位加上，return就行了。
//考虑几个特殊情况：
//1. l1和l2都为null，返回null
//2. l1和l2有一个为null，返回非null的链表
//3. l1和l2长度不同，当操作到其中一个链表最后一个节点时，只将进位（如果有）再继续和另外一个链表的节点相加，
//   直到读到另一个链表的null，然后返回结果链表。
//
//进位的处理方式：
//本位：z = (x + y + carry) % 10; 
//进位：carry = (x + y + carry) / 10;
//
//是否还有什么需要考虑的？
//暂时没有了应该。

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // //两个链表全null的情况
    // if (l1 == NULL && l2 == NULL) return NULL;

    //创建结果链表的头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    //进位
    int carry = 0;
    //遍历两个链表，直到两个链表全为null
    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL)? l1->val : 0;
        int y = (l2 != NULL)? l2->val : 0;
        int currentSum = x + y + carry;
        int currentData = currentSum % 10;
        carry = currentSum / 10;
        //为结果链表分配一个新的节点
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = currentData;
        current->next = NULL;
        //是不是应该把l1和l2指针向后移一位？
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    //是否还有进位？
    if (carry != 0) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
        current->next = NULL;
    }
    //返回结果链表的头节点
    return dummy->next;
}

void traverseList(struct ListNode* head) {
    printf("%d ", head->val);
    head = head->next;
    while (head != NULL) {
        printf("-> %d ", head->val);
        head = head->next;
    }
}

int main() {
    // 本地测试用例
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    int len1 = sizeof(a)/sizeof(a[0]);
    int len2 = sizeof(b)/sizeof(b[0]);
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    l1 = createLinkedList(a, len1);
    l2 = createLinkedList(b, len2);
    struct ListNode* result = addTwoNumbers(l1, l2);
    traverseList(result);
    // 输出结果：7 -> 0 -> 8
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);
    return 0;
}