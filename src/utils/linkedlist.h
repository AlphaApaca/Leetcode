#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 链表节点定义（与 LeetCode 一致）
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 从整型数组创建链表
 * @param arr 数组首地址
 * @param size 数组长度
 * @return 链表头节点指针
 */
struct ListNode* createLinkedList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummy;
    for (int i = 0; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    struct ListNode *head = dummy->next;
    free(dummy); // 释放虚拟头节点
    return head;
}

/**
 * 释放链表内存
 * @param head 链表头节点指针
 */
void freeLinkedList(struct ListNode* head) {
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * 打印链表（用于调试）
 * @param head 链表头节点指针
 */
void printLinkedList(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(", ");
        head = head->next;
    }
    printf("]\n");
}

/**
 * 比较两个链表是否相等（用于测试验证）
 * @param l1 链表1头节点
 * @param l2 链表2头节点
 * @return 相等返回1，否则返回0
 */
int compareLinkedLists(struct ListNode* l1, struct ListNode* l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val != l2->val) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

#endif // LINKEDLIST_H