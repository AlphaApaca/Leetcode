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

    //Testcase 4
    int input4 = 12321;
    int expected4 = 1;
    int actual4 = isPalindrome(input4);
    if (actual4 == expected4) {
        printf("Testcase 4 passed, expected output: %d, actual output: %d\n", expected4, actual4);
    } else {
        printf("Testcase 4 failed, expected output: %d, actual output: %d\n", expected4, actual4);
    }
    //Testcase 5
    int input5 = 123221;
    int expected5 = 0;
    int actual5 = isPalindrome(input5);
    if (actual5 == expected5) {
        printf("Testcase 5 passed, expected output: %d, actual output: %d\n", expected5, actual5);
    } else {
        printf("Testcase 5 failed, expected output: %d, actual output: %d\n", expected5, actual5);
    }
    //Testcase 6
    int input6 = 1234554321;
    int expected6 = 1;
    int actual6 = isPalindrome(input6);
    if (actual6 == expected6) {
        printf("Testcase 6 passed, expected output: %d, actual output: %d\n", expected6, actual6);
    } else {
        printf("Testcase 6 failed, expected output: %d, actual output: %d\n", expected6, actual6);
    }
    //Testcase 7
    int input7 = 1234554329;
    int expected7 = 0;
    int actual7 = isPalindrome(input7);
    if (actual7 == expected7) {
        printf("Testcase 7 passed, expected output: %d, actual output: %d\n", expected7, actual7);
    } else {
        printf("Testcase 7 failed, expected output: %d, actual output: %d\n", expected7, actual7);
    }

}

int main() {
    test_palindrome_number();
    return 0;
}