class UnionFind {
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
        return true;
    }
};

// Many solutions exist to this problem
// DFS can be used to check # of connected components and for cycles
// An adapted BFS could be used too
// Khans could be used for cycle detection
//
// A tree is a connected graph with no simple cycles
//   --> Must be exactly n - 1 edges
//          More = cycle
//          Less = not connected
//  --> Must be exactly one connected component
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        UnionFind uf(n);
        for (const auto& edge : edges) if(!uf.unite(edge[0], edge[1])) return false;
        return true;
    }
};
