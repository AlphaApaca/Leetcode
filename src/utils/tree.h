#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 二叉树节点定义（与 LeetCode 一致）
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * 从层序遍历数组创建二叉树（LeetCode 格式）
 * @param arr 层序遍历数组，NULL 表示空节点
 * @param size 数组长度
 * @return 二叉树根节点指针
 */
struct TreeNode* createTree(int* arr, int size) {
    if (size == 0 || arr[0] == NULL) return NULL;
    
    struct TreeNode **nodes = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    for (int i = 0; i < size; i++) {
        if (arr[i] == NULL) {
            nodes[i] = NULL;
        } else {
            nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[i]->val = arr[i];
            nodes[i]->left = nodes[i]->right = NULL;
        }
    }
    
    int parent = 0, child = 1;
    while (child < size) {
        if (nodes[parent] != NULL) {
            if (child < size) nodes[parent]->left = nodes[child++];
            if (child < size) nodes[parent]->right = nodes[child++];
        }
        parent++;
    }
    
    struct TreeNode *root = nodes[0];
    free(nodes); // 释放临时节点数组
    return root;
}

/**
 * 释放二叉树内存
 * @param root 二叉树根节点指针
 */
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/**
 * 层序遍历二叉树（用于测试结果验证）
 * @param root 二叉树根节点
 * @param returnSize 返回数组长度
 * @return 层序遍历结果数组
 */
int* levelOrder(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode** queue = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int* result = (int*)malloc(1000 * sizeof(int));
    int index = 0;
    
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        if (node == NULL) {
            result[index++] = NULL;
        } else {
            result[index++] = node->val;
            if (node->left != NULL || node->right != NULL) {
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
    }
    
    // 去除末尾多余的 NULL（LeetCode 格式）
    while (index > 0 && result[index-1] == NULL) index--;
    
    *returnSize = index;
    free(queue);
    return result;
}

/**
 * 比较两棵二叉树是否相等
 * @param p 树1根节点
 * @param q 树2根节点
 * @return 相等返回true，否则false
 */
bool compareTrees(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return compareTrees(p->left, q->left) && compareTrees(p->right, q->right);
}

#endif // TREE_H