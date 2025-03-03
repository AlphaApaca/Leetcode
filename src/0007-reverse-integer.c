#include <stdio.h>
#include <stdlib.h>

//先区分正负数，然后将数字转化为字符串，然后翻转字符串，再转化为数字，最后判断是否溢出
int reverse(int x) {
    int sign = x >= 0? 1 : -1; //判断正负数
    //判断取绝对值是否溢出
    if(x == INT_MIN){
        return 0;
    }
    x = abs(x); //取绝对值
    int result = 0;
    while (x > 0) {
        int digit = x % 10; //取个位数
        //判断是否溢出
        if(result > INT_MAX / 10 || (sign == 1 && result == INT_MAX / 10 && digit > 7) || (sign == -1 &&(result == INT_MAX / 10 && digit > 8))){
            return 0;
        }
        result = result * 10 + digit; //将数字转化为字符串
        
        x /= 10; //去掉个位数
    }
    result *= sign; //判断符号，并返回结果

    return result;
}