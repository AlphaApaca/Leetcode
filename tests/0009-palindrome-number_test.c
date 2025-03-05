//0009-palindrome-number_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0009-palindrome-number.c"

void test_palindrome_number() {
    //Testcase 1
    int input1 = 121;
    int expected1 = 1;
    int actual1 = isPalindrome(input1);
    if (actual1 == expected1) {
        printf("Testcase 1 passed, expected output: %d, actual output: %d\n", expected1, actual1);
    } else {
        printf("Testcase 1 failed, expected output: %d, actual output: %d\n", expected1, actual1);
    }

    //Testcase 2
    int input2 = -121;
    int expected2 = 0;
    int actual2 = isPalindrome(input2);
    if (actual2 == expected2) {
        printf("Testcase 2 passed, expected output: %d, actual output: %d\n", expected2, actual2);
    } else {
        printf("Testcase 2 failed, expected output: %d, actual output: %d\n", expected2, actual2);
    }

    //Testcase 3
    int input3 = 10;
    int expected3 = 0;
    int actual3 = isPalindrome(input3);
    if (actual3 == expected3) {
        printf("Testcase 3 passed, expected output: %d, actual output: %d\n", expected3, actual3);
    } else {
        printf("Testcase 3 failed, expected output: %d, actual output: %d\n", expected3, actual3);
    }

}

int main() {
    test_palindrome_number();
    return 0;
}