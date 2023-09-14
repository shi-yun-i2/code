#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    // x:目前遍历的节点
    void dfs(vector<vector<int>>& graph, int x) {
        if (x == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};