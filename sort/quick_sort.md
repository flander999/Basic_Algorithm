# 快速排序

## 要点
借用分治的思想。
1. 选取一个界限（数字）
2. 将整个数组分为左边和右边。
3. 左右两边各自迭代，当当前左边的数大于x，右边的数小于x时，两数交换。保证在该次排序中，左边所有的值均小于x，右边所有的值均大于x
4. 左边数组递归，右边数组递归
5. 递归结束，排序完毕

```
#include <iostream>

using namespace std;

void quick_sort(int nums[], int l, int r){
    if(l > r) return;

    int x = (l+r+1)>>1; //选取一个界限（数字）x
    int i = l-1, j = r+1; 
    while(i < j){
        do i++; while(nums[i] < x);
        do j--; while(nums[j] > x);
        if(i < j) swap(nums[i],nums[j]);
    }
    quick_sort(nums,l,j);
    quick_sort(nums,j+1,r);
}   
```