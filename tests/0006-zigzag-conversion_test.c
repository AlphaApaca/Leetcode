//0006-zigzag-conversion_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0006-zigzag-conversion.c"
//测试代码有问题，好像和编码有关，需要修改
void test_zigzag_conversion() {
    // Testcase 1
    char* s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    char* expected1 = "PAHNAPLSIIGYIR";
    char* result1 = convert(s1, numRows1);
    free(result1);
    if (strcmp(expected1, result1)!= 0) {
        printf("Test failed. expected: %s, result: %s\n", expected1, result1);
    } else {
        printf("Test passed. expected: %s, result: %s\n", expected1, result1);
    }
    // Testcase 2
    char* s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    char* expected2 = "PINALSIGYAHRPI";
    char* result2 = convert(s2, numRows2);
    free(result2);
    if (strcmp(expected2, result2)!= 0) {
        printf("Test failed. expected: %s, result: %s\n", expected2, result2);
    } else {
        printf("Test passed. expected: %s, result: %s\n", expected2, result2);
    }
    // Testcase 3
    char* s3 = "A";
    int numRows3 = 1;
    char* expected3 = "A";
    char* result3 = convert(s3, numRows3);
    free(result3);
    if (strcmp(expected3, result3)!= 0) {
        printf("Test failed. expected: %s, result: %s\n", expected3, result3);
    } else {
        printf("Test passed. expected: %s, result: %s\n", expected3, result3);
    }
}

int main() {
    test_zigzag_conversion();
    return 0;
}