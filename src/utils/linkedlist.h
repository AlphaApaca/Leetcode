#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// 定义链表节点结构
typedef struct Node {
    int data;           // 数据域，这里以存储整数为例
    struct Node* next;  // 指针域，指向下一个节点
} Node;

// 创建新节点
Node* createNode(int data);

// 在链表头部插入节点
Node* insertAtHead(Node* head, int data);

// 遍历链表
void traverseList(Node* head);

// 删除指定值的节点
Node* deleteNode(Node* head, int key);

// 释放链表内存
void freeList(Node* head);

#endif