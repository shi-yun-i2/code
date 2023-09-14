#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 移动整个数组的时间复杂度太高
    int removeElement(vector<int>& nums, int val) {
        // slow指向的元素还没有没使用过
        int slow = 0, fast = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        // slow指向的元素的性质决定了返回值是否加一
        return slow;
    }
};