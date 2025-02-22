//0004-find-median-sorted-arrays_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0004-find-median-sorted-arrays.c"

void test_findMedianSortedArrays() {
    // Testcase 1
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int m1 = 2;
    int n1 = 1;
    double expected1 = 2.0;
    double actual1 = findMedianSortedArrays(nums1, m1, nums2, n1);
    printf("Testcase 1 expected: %f, actual: %f\n", expected1, actual1);

    // Testcase 2
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    int m2 = 2;
    int n2 = 2;
    double expected2 = 2.5;
    double actual2 = findMedianSortedArrays(nums3, m2, nums4, n2);
    printf("Testcase 2 expected: %f, actual: %f\n", expected2, actual2);

    // Testcase 3
    int nums5[] = {};
    int nums6[] = {1};
    int m3 = 0;
    int n3 = 1;
    double expected3 = 1.0;
    double actual3 = findMedianSortedArrays(nums5, m3, nums6, n3);
    printf("Testcase 3 expected: %f, actual: %f\n", expected3, actual3);

    // Testcase 4
    int nums7[] = {2, 2, 4, 4};
    int nums8[] = {2, 2, 2, 4, 4};
    int m4 = 4;
    int n4 = 5;
    double expected4 = 2.0;
    double actual4 = findMedianSortedArrays(nums7, m4, nums8, n4);
    printf("Testcase 4 expected: %f, actual: %f\n", expected4, actual4);
}

int main() {
    test_findMedianSortedArrays();
    return 0;
}