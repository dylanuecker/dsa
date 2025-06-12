class Solution {
public:
    // LC #787 Cheapest Flights Within K Stops
    // Bellman Ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX / 2);
        dist[src] = 0;

        for (int stops = 0; stops <= k; ++stops) {
            vector<int> tmp(dist);

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if (dist[u] + w < tmp[v]) tmp[v] = dist[u] + w;
            }

            dist = tmp;
        }

        return dist[dst] == INT_MAX / 2? -1 : dist[dst];
    }
};
