#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//所有负数都不可能是回文数，return fasle; 如果x是0，则一定是回文数, return true;
//

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }
    int y = 0;
    int temp = x;
    while (temp > 0) {
        //检查溢出
        if (y > INT_MAX / 10 || (y == INT_MAX / 10 && temp % 10 > 7)) {
            return false;
        }
        y = y * 10 + temp % 10;
        temp /= 10;
    }
    return x == y;
}