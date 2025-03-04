//0008-string-to-integer_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0008-string-to-integer.c"

void test_string_to_integer() {
    // Testcase 1
    char* str = "42";
    int actual = myAtoi(str);
    int expected = 42;

    if (actual == expected) {
        printf("Testcase 1 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 1 failed, actual = %d, expected = %d\n", actual, expected);
    }

    // Testcase 2
    str = "   -42";
    actual = myAtoi(str);
    expected = -42;
    if (actual == expected) {
        printf("Testcase 2 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 2 failed, actual = %d, expected = %d\n", actual, expected);
    }

    // Testcase 3
    str = "4193 with words";
    actual = myAtoi(str);
    expected = 4193;
    if (actual == expected) {
        printf("Testcase 3 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 3 failed, actual = %d, expected = %d\n", actual, expected);
    }

    // Testcase 4
    str = "words and 987";
    actual = myAtoi(str);
    expected = 0;
    if (actual == expected) {
        printf("Testcase 4 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 4 failed, actual = %d, expected = %d\n", actual, expected);
    }

    // Testcase 5
    str = "-91283472332";
    expected = -2147483648;
    actual = myAtoi(str);
    if (actual == expected) {
        printf("Testcase 5 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 5 failed, actual = %d, expected = %d\n", actual, expected);
    }
    // Testcase 6
    str = "2147483647";
    expected = 2147483647;
    actual = myAtoi(str);
    if (actual == expected) {
        printf("Testcase 6 passed, actual = %d, expected = %d\n", actual, expected);
    } else {
        printf("Testcase 6 failed, actual = %d, expected = %d\n", actual, expected);
    }
}

int main() {
    test_string_to_integer();
    return 0;
}