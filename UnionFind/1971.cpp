#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int N = 2e5 + 10;
    int f[N];

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void unity(int x, int y) {
        f[find(x)] = find(y);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i < N; i++) {
            f[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            unity(edges[i][0], edges[i][1]);
        }
        return find(source) == find(destination);
    }
};