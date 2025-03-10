#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。

// 提示：

// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s 只包含从 a-z 的小写字母。
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符

// thinkings:
// 1. 这是不是说可以直接用数组？
//    对于p，第一遍遍历，找到.的位置以及带*字母的位置，将p匹配的内容切割开来，存入新的字符串数组p_cut中，新数组的每个元素可能是a-z的单个字母，也可能是. 或者a*-z*；
//    空的元素用null表示，当后面匹配的时候p_cut[j]为null时，表示到达匹配终点。

// 2. 匹配逻辑处理：
//    从左到右匹配，同时分别用i和j遍历s和p_cut:
//      如果p_cut[j]的长度是1，则直接匹配s[i]和p_cut[j]，
//          如果p_cut[j]恰好==‘.’，正常情况下，匹配任意字符，i++,j++；
//              或者：但是当(j>1)&&(p_cut[j-1][1]==‘*’)时，则需要判断s[i-1]是否与p_cut[j-1][0]相等，如果相等，则j++,
//              或者：当*后面有一个或更多个.存在时，假设.的个数是k, 则需要从i-k到i-1，都要判断s[i]是否与p_cut[j-k][0]相等，这个问题其实可以在切割p的处理中解决计算出k的值
//                   然后for循环（）{}
//                   且每一种情况（即.匹配掉*中的字符的个数不同），都要继续往下匹配，
//                   所有的情况中，只要有一种情况匹配成功，则返回true；
//          如果p_cut[j]为a-z的某个字母，则匹配s[i]和p_cut[j]，i++,j++；
//          如果不匹配，则返回false；
//      else: 即p_cut[j]的长度大于1，即p_cut[j]是a*-z*或者.*,
//          匹配s[i]和p_cut[j][0], 
//          如果p_cut[j][0]恰好==‘.’，则匹配任意字符，i++,j++; nb在这里等着我呢，直接结束循环return true就行了；不行，还要看后面有没有要匹配的单字符
//          else, if s[i] == p_cut[j][0], i++，继续匹配;
//                else, j++，继续匹配；

// 特殊情况处理，当a*后遇到.时怎么处理？
// nb在这等着我呢，延伸思考*后还可以出现复数个.，这时候连续的.会非常难处理
// 更正，这是由于我的*的处理方式没有写好，需要重新考虑*如何处理

// 考虑几个问题：
// 如何判断结尾情况？
// 如果s长度小于p匹配的最小长度，即还没有完成匹配，i>len(s)-1，但是j<len(p_cut)，则返回false；
// 如果s长度大于p匹配的最大长度，即s已经把p_cut都匹配完了，但是s还有剩余，这时候 j>len(p_cut)-1, 但是i<len(s), 则返回false；
// 对于刚好完成匹配的情况，i==len(s), j==len(p_cut), 则返回true；

//implement:
bool isMatch(char* s, char* p) {
    //按照分析顺序，我们先进行对于p的元素切割，存入新的char二维数组中
    int len_p = strlen(p);
    char** p_cut = (char**)malloc(len_p * sizeof(char*));
    int j = 0;
    for (int i = 0; i < len_p; i++) {
        if (p[i] == '.') {
            p_cut[j] = (char*)malloc(2 * sizeof(char));
            p_cut[j][0] = '.';
            p_cut[j][1] = '\0';
            j++;
        }
        else if (p[i] == '*') {
            p_cut[j-1] = (char*)realloc(p_cut[j-1], 3 * sizeof(char));
            strcat(p_cut[j-1], "*");
            // if (i > 0 && p[i-1] == '.') {
            //     p_cut[j-1] = (char*)realloc(p_cut[j-1], 3 * sizeof(char));
            //     strcat(p_cut[j-1], "*");
            // }
            // else {
            //     p_cut[j] = (char*)malloc(2 * sizeof(char));
            //     p_cut[j][0] = '*';
            //     p_cut[j][1] = '\0';
            //     j++;
            // }
        }
        else {
            p_cut[j] = (char*)malloc(2 * sizeof(char));
            p_cut[j][0] = p[i];
            p_cut[j][1] = '\0';
            j++;
        }
    }
    printf("p_cut: ");
    for (int i = 0; i < len_p; i++) {
        printf("%s ", p_cut[i]);
    }
    printf("\n");
    // 开始匹配
    int i = 0;
    j = 0;


}