#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector(n, 0));
        int count = 1;
        // 每次循环的起始位置,x表示行,y表示列
        int startX = 0, startY = 0;
        int loopTimes = n / 2;
        int mid = n / 2;
        // 偏移量,想象填充的样子,第二次填充时要比上一次的末尾少填充一个,同时起始位置偏移1,实际上一行少填两个
        int offset = 1;
        int i, j;
        while (loopTimes--) {
            i = startX, j = startY;
            // 左闭右开,循环不变
            for (; j < n - offset; j++) {
                res[i][j] = count++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > startY; j--) {
                res[i][j] = count++;
            }
            for (; i > startX; i--) {
                res[i][j] = count++;
            }
            offset++;
            startX++;
            startY++;
        }
        // 填充中间元素
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};