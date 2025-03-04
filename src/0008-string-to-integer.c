#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数 myAtoi(string s) 的算法如下：

// 空格：读入字符串并丢弃无用的前导空格（" "）
// 符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
// 转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
// 舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
// 返回整数作为最终结果。


int myAtoi(char* str) {
    int len = strlen(str);
    int num = 0;
    int sign = 1;
    for(int i = 0; i < len; i++){
        // if((i > 0) && ((str[i] < '0') || (str[i] > '9')) && ((str[i-1] >= '0') || (str[i-1] <= '9'))){
        //     return num *sign;
        // }
        if(str[i] ==' '){
            if((i > 0) && (str[i-1] != ' ')){
                return num * sign;
            }
            continue;
        }
        if(str[i] == '+' || str[i] == '-'){
            if((i == 0) || ((i > 0) && (str[i-1] == ' '))){
                sign = (str[i] == '+')? 1 : -1;
            }else{
                break;
            }
        }else if(str[i] >= '0' && str[i] <= '9'){
            //先检测是否会溢出
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] > '7')){
                return (sign == 1)? 2147483647 : -2147483648;
            }
            num = num * 10 + (str[i] - '0');
        }else{
            break;
        }

    }
    return num * sign;
}