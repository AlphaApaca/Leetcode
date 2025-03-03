//0007-reverse-integer_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0007-reverse-integer.c"

void test_reverse_integer() {
    // Testcase 1
    int x = 123;
    int expected = 321;
    int actual = reverse(x);
    if (actual == expected) {
        printf("Testcase 1 passed, expected: %d, actual: %d\n", expected, actual);
    } else {
        printf("Testcase 1 failed, expected: %d, actual: %d\n", expected, actual);
    }
    // Testcase 2
    x = -123;
    expected = -321;
    actual = reverse(x);
    if (actual == expected) {
        printf("Testcase 2 passed, expected: %d, actual: %d\n", expected, actual);
    } else {
        printf("Testcase 2 failed, expected: %d, actual: %d\n", expected, actual);
    }
    // Testcase 3
    x = 120;
    expected = 21;
    actual = reverse(x);
    if (actual == expected) {
        printf("Testcase 3 passed, expected: %d, actual: %d\n", expected, actual);
    } else {
        printf("Testcase 3 failed, expected: %d, actual: %d\n", expected, actual);
    }
    // Testcase 4
    x = 0;
    expected = 0;
    actual = reverse(x);
    if (actual == expected) {
        printf("Testcase 4 passed, expected: %d, actual: %d\n", expected, actual);
    } else {
        printf("Testcase 4 failed, expected: %d, actual: %d\n", expected, actual);
    }
    // Testcase 5
    x = 1534236469;
    expected = 0;
    actual = reverse(x);
    if (actual == expected) {
        printf("Testcase 5 passed, expected: %d, actual: %d\n", expected, actual);
    } else {
        printf("Testcase 5 failed, expected: %d, actual: %d\n", expected, actual);
    }

}

int main() {
    test_reverse_integer();
    return 0;
}