#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    // 只要可能产生越界问题,毫不犹豫选择左闭右闭节省时间
    bool isPerfectSquare(int num) {
        int left = 0, right = 1e6;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if ((long long) mid * mid < num) {
                left = mid + 1;
            } else if ((long long) mid * mid > num) {
                right = mid - 1;
            } else {
                // 寻找确定的值需要在while循环中返回
                return true;
            }
        }
        // 此时未找到
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = -1, right = 1e6;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if ((long long) mid * mid < num) {
                left = mid;
            } else if ((long long) mid * mid > num) {
                right = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};