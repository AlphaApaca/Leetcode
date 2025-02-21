// tests/0003-length-of-longest-substring_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0003-length-of-longest-substring.c" // 引入源码中的函数

void test_lengthOfLongestSubstring() {
    char* s1 = "abcabcbb";
    int expected1 = 3;
    int actual1 = lengthOfLongestSubstring(s1);
    printf("Test 1: expected: %d, actual: %d\n", expected1, actual1);
    char* s2 = "bbbbb";
    int expected2 = 1;
    int actual2 = lengthOfLongestSubstring(s2);
    printf("Test 2: expected: %d, actual: %d\n", expected2, actual2);
    char* s3 = "pwwkew";
    int expected3 = 3;
    int actual3 = lengthOfLongestSubstring(s3);
    printf("Test 3: expected: %d, actual: %d\n", expected3, actual3);
    char* s4 = " ";
    int expected4 = 1;
    int actual4 = lengthOfLongestSubstring(s4);
    printf("Test 4: expected: %d, actual: %d\n", expected4, actual4);
    char* s5 = "00ab0c0aa0";
    int expected5 = 4;
    int actual5 = lengthOfLongestSubstring(s5);
    printf("Test 5: expected: %d, actual: %d\n", expected5, actual5);
    char* s6 = "aab";
    int expected6 = 2;
    int actual6 = lengthOfLongestSubstring(s6);
    printf("Test 6: expected: %d, actual: %d\n", expected6, actual6);
}//这里在调试的时候应该是出现了线程冲突问题，后续再尝试解决

int main() {
    test_lengthOfLongestSubstring();
    return 0;
}