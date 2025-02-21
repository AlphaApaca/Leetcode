这是Alpaca的C语言学习笔记

# 1. 基本语法

## 0. Hello World

~~~c
#include <stdio.h>

int main()
{
    printf("Hello, World! \n");
    
    return 0;
}
~~~

C语言变量前加*，表示指针变量，可以指向其他变量。




# 题带知识点

## 1. 指针

~~~c
int* p; // 声明一个整型指针变量p
~~~

变量类型后面加*，表示该变量p是一个指针变量，这里这个 *“变量类型”* 仅是用于声明它可以指向何种变量的内存地址。（为什么在初始化指针的时候要声明指针指向的变量类型？为什么不能有一个可以指向所有变量的一个普遍的指针类？很好理解，在相同机器中，不同变量的在内存中所占空间大小通常是不一致的，内存地址只是存储了变量的起始地址，并不关心变量的具体类型，即只获取内存地址并不知道变量所占的具体空间大小。）


指针本质上是直接拿到一串存储在内存中的地址（类比深拷贝浅拷贝的内容）

所以，为什么使用指针？

动态内存分配：指针可以用来动态分配内存，而不用事先声明内存大小。
（C语言中为什么要事先声明内存大小？为什么需要动态分配内存）

## 2. 链表

参考资料：

[菜鸟教程-C结构体-7.用指针处理链表](https://www.runoob.com/w3cnote/c-structures-intro.html)

**（1）malloc 函数**

```c
void *malloc(unsigned int size);
```

作用是在内存的动态存储区中分配一个长度为 size 的连接空间。些函数的值（即返回值）是一个指向分配空间起始地址的指针（基类型为 void）。如果些函数未能成功地执行（例如内存空间不足）则返回空指针 NULL。



以 [linkedlist.h](src\utils\linkedlist.h) 中的createLinkedList函数为例：

```c
struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode *current = dummy;
```
含义就是先用 malloc 函数分配一个 ListNode 结构体的内存，然后将该内存地址赋值给 dummy 指针，并将 dummy 指针赋值给 current 指针。这样 dummy 指针就指向了链表的第一个节点，current 指针则指向了当前正在处理的节点。

```c
for (int i = 0; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));//用 malloc 函数分配一个新的节点，并将其指针赋值给 current->next
        current = current->next;//将 current 指针指向新的节点，然后继续处理下一个节点
        current->val = arr[i];//为新节点赋值
        current->next = NULL;//为新节点的 next 指针赋值为 NULL，表示这是目前的最后一个节点（如果还有，则在下一轮循环中赋值）
    }
```

**（2）calloc 函数**

```c
void *calloc(unsigned n, unsigned size);
```

其作用是在内存的动态区存储中分配 n 个长度为 size 的连续空间。函数返回一个指向分配空间起始地址的指针，如果分配不成功，返回 NULL。 用 calloc 函数可以为一维数组开辟动态存储空间， n 为数组元素个数，每个元素长度为 size。

**（3）free 函数**

```c
void free(void *p);
```

其作用是释放由 p 指向的内存区，使这部分内存区能被其它变量使用， p 是最后一次调用 calloc 或 malloc 函数时返回的值。free 函数无返回值。 请注意：以前的C版本提供的 malloc 和 calloc 函数得到的是指向字符型数据的指针。ANSI C 提供的 malloc 和 calloc 函数规定为 void * 类型。

### -> 符号在C语言中的作用：

一句话总结，就是" . "，但是在c语言中功能更强大，应用范围更广（因为很多时候离不了指针）

1. C语言中也可以使用" . "去访问对象的attributes，但是当遇到动态分配内存创建结构体对象时就不可以了（这个时候只能得到一个指向该对象的指针）//其实还是没太懂动态分配内存的部分
2. 函数传参传指针比把整个对象传进去效率更高
3. 链表、树等复杂数据结构中，全是指针。

## 3. 字符串

初始化空字符串：

```c
char cur_str[len];
    memset(cur_str, '\0', len);
```
意思是，从cur_str的起始位置开始，用'\0'填充len个字符，这样cur_str就变成了一个空字符串。

strchr函数：

```c
char *strchr(const char *s, int c);
```

作用是查找字符串s中第一个出现字符c的位置（返回指向该字符的指针），如果没有找到，则返回NULL。

如果要返回该字符的索引，可以使用指针减指针的方式：

```c
char* ptr = strchr(str, c);//找到重复字符的位置
int index = ptr - str;//找到重复字符的位置
```

将字符串某个字符之前（包含这个字符）的字符删掉，后面字符随之往前移动：

 [0003-length-of-longest-substring.c](src\0003-length-of-longest-substring.c) 中的内容

```c
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
```

