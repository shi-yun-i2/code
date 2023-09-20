#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    void reverseString(vector<char>& s) {
        // 交换的次数是s.size() / 2次,i从0开始
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
