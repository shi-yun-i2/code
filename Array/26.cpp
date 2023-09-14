#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        // slow指向的是被使用过的元素的下标
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                // 使用时slow要先++
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // slow指向的是被使用过的元素的下标
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                // fast - slow = 1时slow++之后和fast相等,不需要复制
                if (fast - slow > 1) {
                    // 仍然需要复制到slow + 1的位置
                    nums[slow + 1] = nums[fast];
                }
                slow++;
            }
            fast++;
        }
        return slow + 1;
    }
};