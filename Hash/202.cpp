#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool isHappy(int n) {
        unordered_set<int> sett;
        // 需要一个变量sum记录每一轮循环的数位平方和
        int sum = 0;
        while (sum != 1) {
            // sum变量每轮循环要置为0
            sum = 0;
            // 需要一个变量n储存值计算数位平方和
            while (n != 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            // 更新变量n
            n = sum;
            // 是否有循环
            if (sett.count(sum)) {
                return false;
            } else {
                sett.insert(sum);
            }
        }
        return true;
    }
};

class Solution2 {
public:
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sett;
        // sum初始化为n
        int sum = n;
        while (sum != 1) {
            // 利用函数形参赋值
            sum = getSum(sum);
            if (sett.count(sum)) {
                return false;
            } else {
                sett.insert(sum);
            }
        }
        return true;
    }
};

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sett;
        while (1) {
            int sum = getSum(n);
            // 注意每一轮都要更新n的值
            n = sum;
            if (sum == 1) {
                return true;
            }
            if (sett.count(sum)) {
                return false;
            } else {
                sett.insert(sum);
            }
        }
    }
};