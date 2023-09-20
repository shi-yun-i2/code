#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        // res写在最前面处理特殊情况
        vector<int> res;
        // 两个逻辑符号是短路运算,调整顺序可以避免程序出错
        if (v.size() == 0 || v[0].size() == 0) {
            return res;
        }
        int n = v.size();
        int m = v[0].size();
        int startX = 0, startY = 0;
        // 初始化为1使区间为左闭右开
        int offset = 1;
        int i, j;
        // 循环次数和中间位置由较小的维度确定
        int loopTimes = min(n, m) / 2;
        int mid = min(n, m) / 2;
        while (loopTimes--) {
            i = startX, j = startY;
            for (; j < m - offset; j++) {
                res.push_back(v[i][j]);
            }
            for (; i < n - offset; i++) {
                res.push_back(v[i][j]);
            }
            for (; j > startY; j--) {
                res.push_back(v[i][j]);
            }
            for (; i > startX; i--) {
                res.push_back(v[i][j]);
            }
            offset++;
            startX++;
            startY++;
        }
        // 两者中较小者为奇数时会产生竖向或者横向的一条
        if (min(n, m) % 2 == 1) {
            // 分类讨论是一行还是一列还是一个点
            // 最后一行列需要左闭右闭
            if (n > m) {
                for (i = startX; i <= n - offset; i++) {
                    res.push_back(v[i][startY]);
                }
            } else if (n < m) {
                for (j = startY; j <= m - offset; j++) {
                    res.push_back(v[startX][j]);
                }
            } else {
                res.push_back(v[mid][mid]);
            }
        }
        return res;
    }
};
