// bfs graph coloring
// can also use dfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> coloring(n, -1);
        for (int i = 0; i < n; ++i) {
            if (coloring[i] == -1) {
                coloring[i] = 0;
                queue<int> q;
                q.push(i);
                int color = 1;
                while(!q.empty()) {
                    for (int i = q.size(); i > 0; --i) {
                        int node = q.front();
                        q.pop();
                        for (int neighbor : graph[node]) {
                            if (coloring[neighbor] == -1) {
                                coloring[neighbor] = color;
                                q.push(neighbor);
                            } else if (coloring[neighbor] != color) {
                                return false;
                            }
                        }
                    }
                    color ^= 1;
                }
            }
        }
        return true;
    }
};
