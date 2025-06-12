class Solution {
public:
    // LC #787 Cheapest Flights Within K Stops
    // Shortest Path Faster Algorithm (SPFA)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n); 

        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];

            g[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        
        q.push({src, 0});

        int stops = 0;
        while (!q.empty() && stops <= k) {
            for (int i = q.size(); i > 0; --i) {
                auto [curr, price] = q.front();
                q.pop();

                for (auto &[v, w] : g[curr]) {
                    int cost = price + w;
                    if (cost >= dist[v]) continue;
                    dist[v] = cost;
                    q.push({v, cost});
                }
            }

            ++stops;
        }

        return dist[dst] == INT_MAX? -1 : dist[dst];
    }
};
