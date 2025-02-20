// tests/0002-add-two-numbers_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0002-add-two-numbers.c" // 引入源码中的函数

void traverseList(struct ListNode* head) {
    printf("%d ", head->val);
    head = head->next;
    while (head != NULL) {
        printf("-> %d ", head->val);
        head = head->next;
    }
}

void test_addTwoNumbers() {
    //测试用例1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    struct ListNode* l1 = createLinkedList(arr1, size1);
    struct ListNode* l2 = createLinkedList(arr2, size2);
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Test case 1: ");
    traverseList(result);
    printf("\n");
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);

    //测试用例2
    int arr3[] = {0};
    int arr4[] = {0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    l1 = createLinkedList(arr3, size3);
    l2 = createLinkedList(arr4, size4);
    result = addTwoNumbers(l1, l2);
    printf("Test case 2: ");
    traverseList(result);
    printf("\n");
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);

    //测试用例3
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    l1 = createLinkedList(arr5, size5);
    l2 = createLinkedList(arr6, size6);
    result = addTwoNumbers(l1, l2);
    printf("Test case 3: ");
    traverseList(result);
    printf("\n");
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);
}

int main() {
    test_addTwoNumbers();
    return 0;
}