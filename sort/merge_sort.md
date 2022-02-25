# 归并排序

## 要点

利用二分，不断将数组分为更小的两个数组，直到最后只剩下一个数，然后将两个仅有一个数的数组排序，并完成递归返回上一层。

与快排在代码上不同的地方在于，归并排序是先递归后排序。并且需要一个额外的数组存储变化，最后再复制回原数组。


```c++
#include <iostream>

using namespace std;

void merge_sort(int nums[], int l, int r){
    if(l > r) return;

    int mid = (l+r)>>1;
    merge_sort(nums,l,mid);
    merge_sort(nums,mid+1,r);

    int i = l, j = mid+1,k = 0;
    int tnp[r-l+1];
    while(i <= mid && j <=r){
        if(nums[i] <= nums[j]) tmp[k++] = nums[i++];
        else tmp[k++] = nums[j++];
    }
    while(i <= mid){
        tmp[k++] = nums[i++];
    }
    while( j <= r){
        tmp[k++] = nums[j++];
    }

    for(i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
}
```