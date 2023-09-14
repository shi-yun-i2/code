#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        // 对左右端点的初始化决定循环结束条件
        // 左闭右闭 模糊查找时需要使用ans变量记录合法值
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            // mid写在前面
            // mid的值大了从左区间找,mid的值小了从右区间找,移动相应指针
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// 最常用的二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 左开右开 模糊查找时不需要使用ans变量记录合法值 直接返回指针 (完全无溢出情况时使用)
        // 明确left和right的取值范围
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};