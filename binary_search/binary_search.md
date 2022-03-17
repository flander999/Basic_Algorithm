# 二分查找

## 时间复杂度

$O(\log n)$, 通常因为每一次查找可以缩减当前数量一半的元素。

需要注意的是，均衡搜索树(BBST/BBT)的插入和删除以及查找的时间复杂度也为 $O(\log n)$.

## 基础思路

通过单次条件判断，将需要搜索或查找的内容减半，以达到更快的运行速度。通常是对半分，但根据条件也可以进行不同的分割。


## Leetcode上的相关题目以及链接

[704.二分查找](https://leetcode-cn.com/problems/binary-search/)

[4.寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)
