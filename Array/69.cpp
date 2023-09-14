#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 左开右开
        int left = -1, right = 1e6;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            // 列出需要满足的条件,分析可行区的方向
            if ((long long) mid * mid <= x) {
                // 移动可行区对应的指针
                left = mid;
            } else {
                right = mid;
            }
        }
        // 返回可行区对应的指针
        // 寻找不大于或者不小于某个值的值时在最后返回指针,while循环中不断更新指针位置
        return left;
    }
};