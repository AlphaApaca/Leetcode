#include <stdio.h>
#include <stdlib.h>

//耷拉眼一看，暴力求解
int* twoSum_0(int* nums, int numsSize, int target, int* returnSize) {
    // 你的代码逻辑
    int indices[2];
    *returnSize = 0;
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                *returnSize = 2;
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
    return NULL;
}

//仔细想想
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 你的代码逻辑
    //先排序，然后寻找一下有没有数学办法来解决这个问题

    //排序后，首先可以明显排除的是，如果target比数组中最小的数还小，则不存在target的解；如果target比数组中最大的数还大，则不存在target的解。
    //如果target小于数组中的某些数，可以直接把大于target的数全部排除。
    //我们接下来只关注小于等于target的数。不幸的是，这样即使是已经将数组大小缩小，但对于搜索算法而言，仍然是O(n^2)的复杂度。
    //双指针法可以解决这个问题，双指针法的复杂度是O(n)，但是它需要额外的空间来存储指针。

    // 先排序
    //运行测试用例有问题，问题出现在需要return的是对应数字排序前的数组的index，而不是对应数字排序后的数组index。
    ////或许在排序时需要记录下排序后每个数字在排序前的数组中的位置，可以建立一个相同大小的int数组，记录坐标变换。

    int indexers[numsSize];
    for(int i = 0; i < numsSize; i++){
        indexers[i] = i;
    }
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] > nums[j]){
                int temp = nums[i];
                int temp_index = indexers[i];
                nums[i] = nums[j];
                indexers[i] = indexers[j];
                nums[j] = temp;
                indexers[j] = temp_index;
            }
        }
    }
    //时间复杂度O(nlogn)
    
    // 双指针法
    int* indices = (int*)malloc(2*sizeof(int));
    //为什么要用malloc而不是new？
    //因为malloc返回的指针是动态分配的，而new返回的指针是堆上分配的，两者的区别在于，malloc返回的指针必须通过free来释放，而new返回的指针会自动被系统释放。
    //所以在这里，我们使用malloc来分配空间，并在函数返回后释放空间。
    //为什么不能由系统释放？
    //因为题目要求返回的是指针，而系统分配的指针无法返回给调用者，只能由调用者释放。
    *returnSize = 0;
    //为什么要改变*returnSize？
    //因为如果没有找到target的解，*returnSize应该为0，而如果找到了，*returnSize应该为2。
    //虽然没有在结果里输出returnSize的值，但它确实会在这一过程中被改变，而不需要return操作。
    //逐渐熟悉了
    int left = 0;
    int right = numsSize-1;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            *returnSize = 2;
            indices[0] = indexers[left];
            indices[1] = indexers[right];
            return indices;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return NULL;
}