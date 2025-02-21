#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//第一感，一个变量存储当前子串，一个变量存储历史最长字串的长度
//不需要用变量存储已经出现的字符，我们只需要比较历史最长字串的长度和当前处理字串的长度即可
//每次寻找是否有重复的字符都是拿正在读到的字母和当前正在处理的子串对比就可以，可以用memchr函数来查找子串中的某个字符是否在子串中出现过
//如果出现过，则将当前处理的子串长度和历史最长字串长度对比，更新历史最长字串的长度
//并找到当前子串中重复字符的位置，将其前面的字符都删掉，继续读下一个字符
//如果没有出现过，则更新当前子串的长度，直到读完整个字符串

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int max_len = 0;
    int cur_len = 0;
    char cur_str[len+1];
    memset(cur_str, '\0', len+1);
    for(int i=0; i<len; i++) {
        if(memchr(cur_str, s[i], cur_len)!= NULL) {
            max_len = cur_len > max_len ? cur_len : max_len;
            char* ptr = strchr(cur_str, s[i]);//找到重复字符的位置
            int pos = ptr - cur_str + 1;//找到重复字符的位置（非索引，而是第X个字符）
            //将重复字符以及其前面的字符都删掉
            //先将不包含重复字符的剩余子字符串往前移动
            for(int j=pos; j<cur_len; j++) {
                cur_str[j-pos] = cur_str[j];
            }
            //再将剩余的位置变为'\0'
            cur_len -= pos;
            memset(cur_str+cur_len, '\0', len-cur_len+1);
            //然后将新读到的字符加入下一位
            cur_str[cur_len] = s[i];
            cur_len++;
        } else {
            cur_str[cur_len] = s[i];
            cur_len++;
        }
    }
    max_len = cur_len > max_len ? cur_len : max_len;
    return max_len;
}