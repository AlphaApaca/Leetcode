#include <stdio.h>
#include <stdlib.h>


//从题目开始分析，一开始我并没有看到正序数列，这让我很困惑，因为我已知的所有排序算法的最小时间复杂度是归并排序
//而归并排序的最坏情况时间复杂度是O(nlogn)，不满足题目要求的O(logn)，再读题才发现已经被排好了，
//再从题目要求的时间复杂度作为入手点，O(logn)，二分查找满足题目要求，但是二分查找只能对于有序数组查找，
//而题目中给出的是两个有序数组，所以需要找到一个方法来处理这种情况。
//
//另外平衡二叉搜索树的查找等操作是否也可以满足？

//二分查找显然不能满足题目要求，因为题目要求的是两个有序数组，而二分查找只能查找单个数组。
//所以，我们需要找到一种方法来处理两个有序数组的合并，使得合并之后的数组仍然有序。
//
//一种方法是使用归并排序的merge函数的思路，先将两个数组合并，然后再找出合并之后的数组的中位数。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 合并两个数组
    int arr[nums1Size + nums2Size];
    
    int i = 0; // 初始化第一个子数组的索引
    int j = 0; // 初始化第二个子数组的索引
    int k = 0; // 初始归并子数组的索引
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            arr[k] = nums1[i];
            i++;
        } else {
            arr[k] = nums2[j];
            j++;
        }
        k++;
    }

    // 复制 nums1[] 的剩余元素
    while (i < nums1Size) {
        arr[k] = nums1[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < nums2Size) {
        arr[k] = nums2[j];
        j++;
        k++;
    }
    // 找出合并之后的数组的中位数
    int mid = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) % 2 == 0) {
        return (double)(arr[mid - 1] + arr[mid]) / 2;
    } else {
        return (double)arr[mid];
    }
}//这个算法的时间复杂度是O(m+n), 不符合题意，但是以外的通过了测试，我决定先原谅自己，明天有空再看。


//失败方案：
//wc我好像发现一个诡异的东西，两个有序数组合并之后的中位数好像等于两个数组中位数的中位数
//这种方法的时间复杂度是O(1)，不是我想不懂了，题目怎么要求O(logn)的？
//有O(1)的解法为什么要求O(logn)的？
//好吧事实证明没有这么好的事情，当出现重复元素且数组长度为奇数时，这种解法就不行了
// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//     //尝试一下这个诡异的思路
//     //先分别找到两个数组的中位数
//     //先判断两个数组的长度奇偶
//     //先判断数组存在null的情况
//     //然后分别找到两个数组的中位数
//     //然后取两个中位数的平均值
//     //最后返回这个平均值
//     if(nums1Size !=0 && nums2Size !=0){
//         double mid1 = 0, mid2 = 0;
//         if(nums1Size % 2 == 0){
//             double mid1_left = nums1[(nums1Size/2) - 1];
//             double mid1_right = nums1[nums1Size/2];
    
//             mid1 = (mid1_left + mid1_right)/2;
//             //注意，这里如果不分别声明double的左右两个变量，/2操作可能会被认为是int的整除操作
//         }else{
//             mid1 = nums1[(nums1Size-1)/2];
//         }
    
//         if(nums2Size % 2 == 0){
//             double mid2_left = nums2[(nums2Size/2) - 1];
//             double mid2_right = nums2[nums2Size/2]; 
    
//             mid2 = (mid2_left + mid2_right)/2;
//         }else{
//             mid2 = nums2[(nums2Size-1)/2];
//         }
//         //然后取两个中位数的平均值
//         return (mid1 + mid2) / 2;
//     }else if (nums1Size == 0 && nums2Size !=0)
//     {
//         double mid2 = 0;
//         if(nums2Size % 2 == 0){
//             double mid2_left = nums2[(nums2Size/2) - 1];
//             double mid2_right = nums2[nums2Size/2]; 
    
//             mid2 = (mid2_left + mid2_right)/2;
//         }else{
//             mid2 = nums2[(nums2Size-1)/2];
//         }
//         return mid2;
//     }else if (nums1Size !=0 && nums2Size == 0)
//     {
//         double mid1 = 0;
//         if(nums1Size % 2 == 0){
//             double mid1_left = nums1[(nums1Size/2) - 1];
//             double mid1_right = nums1[nums1Size/2];
    
//             mid1 = (mid1_left + mid1_right)/2;
//         }else{
//             mid1 = nums1[(nums1Size-1)/2];
//         }
//         return mid1;
//     }else{
//         return 0;
//     }
// }
