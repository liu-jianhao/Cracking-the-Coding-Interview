class Solution {
    vector<unordered_set<int>> edge;
    unordered_set<int> visited;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        edge.resize(n);
        for (auto e : graph) {
            edge[e[0]].insert(e[1]);
        }
        return dfs(start, target);
    }

    bool dfs(int cur, int target) {
        if (visited.count(cur)) {
            return false;
        }
        if (cur == target) {
            return true;
        }
        for (auto v: edge[cur]) {
            if (dfs(v, target)) {
                return true;
            }
        }
        return false;
    }
};