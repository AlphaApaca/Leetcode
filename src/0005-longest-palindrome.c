#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//thinking:
//现在考虑用一种方式来表示一个回文子串，可以用对称中心和对称部分的长度来表示，
//肯定是要遍历了，可以从最长情况开始，然后每次更新中心位置，以及当从左到右遍历时遍历到最右端，更新对称部分的长度，
//因为是从最长的情况开始寻找的，所以最先找到的回文子串就是最长的，return即可。
//这样的时间复杂度是多少？
//初始对称中心只有一个，随着长度每次-1，这一长度的对称中心个数将会是1+(strlen(s)-symmetry_len)个，
//思路没问题，内存限制爆了，每个子串都分别创建内存用太多了，直接对原字符串进行操作就可以。
//我选择先原谅，奇偶的分类讨论给我搞得晕晕的，最后告诉我爆内存tnnd。

// implementation:
char* isPalindrome(char* s) {
    int symmetry_len = strlen(s);
    int symmetry_center = symmetry_len / 2 - !(symmetry_len % 2);
    for(int i=0; i<=symmetry_len/2-!(symmetry_len%2); i++) {
        if(s[symmetry_center-i]!= s[symmetry_center+!(symmetry_len%2)+i]) {
            return NULL;
        }
    }
    return s;
}

//将字符串s的从中心palindrome_center左右共palindrome_len个字符作为回文子串，存入palindrome，并返回。
char* getSubstring(char* s, int palindrome_center, int palindrome_len) {
    char* palindrome = (char*)malloc(palindrome_len+1);
    strncpy(palindrome, s+palindrome_center+!(palindrome_len % 2)-palindrome_len/2, palindrome_len);
    palindrome[palindrome_len] = '\0';
    return palindrome;
}

char* longestPalindrome(char* s) {
    //初始化变量
    int palindrome_len = strlen(s);
    int palindrome_center = palindrome_len / 2 - !(palindrome_len % 2);
    //用一个变量存储字串
    char* palindrome = (char*)malloc(palindrome_len+1);
    //遍历
    while(palindrome_len > 0) {
        //更新回文子串
        palindrome = getSubstring(s, palindrome_center, palindrome_len);
        if(isPalindrome(palindrome)) {
            return palindrome;
            
        }
        //更新数据
        if(palindrome_center+ palindrome_len/2 == strlen(s)-1) {
            palindrome_len--;
            palindrome_center = palindrome_len / 2 - !(palindrome_len % 2);
        }else{
            palindrome_center++;
        }
    }
    return "";
}