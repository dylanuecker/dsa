// LC #802. Find Eventual Safe States
// my original solution used DFS cycle detection
// this uses topological sort (kahn's algorithm)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n);
        vector<vector<int>> revAdj(n);

        for (int i = 0; i < n; ++i) {
            for (int node : graph[i]) {
                revAdj[node].push_back(i);
                ++inDegree[i];
            }
        } 

        queue<int> q;
        for (int i = 0; i < n; ++i) if (inDegree[i] == 0) q.push(i);

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : revAdj[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) if (safe[i]) ans.push_back(i);
        return ans;
    }
};
