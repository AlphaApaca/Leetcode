// tests/0001-two-sum_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0001-two-sum.c" // 引入源码中的函数

void test_twoSum() {
    // 测试用例1
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, 4, target1, &returnSize1);
    if (returnSize1 == 2 && result1[0] == 0 && result1[1] == 1) {
        printf("Test Case 1: Passed\n");
    } else {
        printf("Test Case 1: Failed\n");
    }
    free(result1); // 释放动态内存

    // 测试用例2（可添加更多）
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, 3, target2, &returnSize2);
    if (returnSize2 == 2 && result2[0] == 1 && result2[1] == 2) {
        printf("Test Case 2: Passed\n");
    } else {
        printf("Test Case 2: Failed\n");
    }
    free(result2);
}

int main() {
    test_twoSum();
    return 0;
}