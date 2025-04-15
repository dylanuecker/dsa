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
