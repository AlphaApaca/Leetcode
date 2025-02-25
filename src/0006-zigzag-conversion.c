#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//zigzag conversion
//z字型变化，其实是将字符串按照（下-右上-下-右上-）的顺序循环排列，
//虽然z字型变换后会的形式有空格，但是对于最终生成的字符串来说并没有什么影响，
//实际上就是把字符串按照给定的numRows的值，将字符串从上往下排列numRow行，然后再从下往上去头去尾从中间排列numRow-2行，以此类推。
//按照这个方案
//第一行的字符分别是原字符串的第0个{0*(numRows+numRows-2)+0}、                                          第6个{1*(numRows+numRows-2)+0}、                        第12个{2*(numRows+numRows-2)}
//第二行的字符分别是原字符串的第1个{0*(numRows+numRows-2)+1}、第5个{0*(numRows+numRows-2)+j+2}、第7个{1*(numRows+numRows-2)+1}、第11个{1*(numRows+numRows-2)+numRows-1+2}
//第三行的字符分别是原字符串的第2个{0*(numRows+numRows-2)+2}、第4个{0*(numRows+numRows-2)+j+1}、第8个{1*(numRows+numRows-2)+2}、第10个{1*(numRows+numRows-2)+numRows-1+1}
//第四行的字符分别是原字符串的第3个{0*(numRows+numRows-2)+3}、                                        第9个{1*(numRows+numRows-2)+3}

//所以每一位可以被表示为:{i*(numRows+numRows-2)+j+k}
//i的数量初始等于0，最大为(strlen(s)-1)/(numRows+numRows-2)，因为i只和index有关，而不是长度
//j的数量初始等于0，最大为numRows-1，(j%(numRows+numRows-2))
//k的数量初始等于numRows-2，最小为0.（去头去尾）


//现在可以看一下新字符串的index和原字符串的index的对应关系：
//第1行的字符串先排列：所以是先把原字符串中的第{i*(numRows+numRows-2)+0}个字符依次放到新的字符串的前(strlen(s)-1)/(numRows+numRows-2)个位置上

//第2到numRows-1行的字符串继续排列，从第(strlen(s)-1)/(numRows+numRows-2)+1个字符开始，将{0*(numRows+numRows-2)+j}和{0*(numRows+numRows-2)+j+k}(如果存在)成对放入接下来的字符串中，

//第numRows行字符串最后排列，
//将原字符串的第{i*(numRows+numRows-2)+numRows-1}放到新字符串从第(strlen(s)-1-((strlen(s)-numRows)/(numRows+numRows-2)))个字符开始，
//长度为(strlen(s)-numRows)/(numRows+numRows-2)，到第strlen(s)-1个字符结束。

//要明确的是，写算法的时候只能一起写，
//可以先把第1行和第numRows行的字符串排列好，然后再将第2到numRows-1行的字符串排列好。

//首先可以明确的是z字型变化并不会改变字符串的长度，所以可以直接声明一个和字符串一样长的空char数组，然后按照上述规则填充数组即可。
// char* convert(char* s, int numRows) {
//     //声明新字符串和原字符串一样长的char数组
//     char* newStr = (char*)malloc(sizeof(char)*(strlen(s)+1));
//     //初始化新字符串为空格
//     memset(newStr, ' ', strlen(s)+1);

//     //考虑两个特例
//     //当numRows==1或当numRows大于字符串长度时，直接复制原字符串到新字符串
//     if(numRows == 1 || numRows > strlen(s)) {
//         strcpy(newStr, s);
//         return newStr;
//     }

//     //下面开始正常排列
//     //用x和y来表示在将旧字符串变换后的第一行和最后一行分配给新字符串的坐标
//     int x = 0;
//     int y = strlen(s)-1-((strlen(s)-numRows)/(numRows+numRows-2));
//     //先创建i主管的循环
//     for(int i = 0; i <= ((strlen(s)-1)/(numRows+numRows-2)); i++){
        
//         //对于第一行和第numRows行的排列，可以先处理（因为j和k不一定存在）
//         //先处理第一行
//         if(x<=(strlen(s)-1)/(numRows+numRows-2)){
//             newStr[i*(numRows+numRows-2)] = s[x];
//             x++;
//         }
//         //再处理第numRows行
//         newStr[i*(numRows+numRows-2)+numRows-1] = s[y];
//         y++;
//         //然后处理中间的行
//         //这里要先判断j和k是否存在
//         //只有当numRows>2时才可能存在j和k
//         if(numRows > 2) {
//             //计算j和k的最大值
//             int jMax = (numRows-1);
//             int kMax = (strlen(s)-1)/(numRows+numRows-2)-i;
//             //计算j和k的最小值
//             int jMin = 0;
//             int kMin = 0;
//             //计算j和k的初始值
//             int j = 0;
//             int k = numRows-2;
//             //开始处理中间的行
//             for(int j = 0; j < jMax; j++) {

//             }
//         }
//     }
//     return newStr;
// }

// 好短，好漂亮，好值得学习，我写的是什么东西（哭
char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        // 如果行数为 1 或者行数大于等于字符串长度，直接返回原字符串
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    // 计算周期长度
    int cycleLen = 2 * numRows - 2;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    // 逐行处理
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycleLen) {
            result[index++] = s[j];
            // 中间行需要处理额外的字符
            if (i != 0 && i != numRows - 1) {
                int nextIndex = j + cycleLen - 2 * i;
                if (nextIndex < len) {
                    result[index++] = s[nextIndex];
                }
            }
        }
    }
    result[index] = '\0';
    return result;
}