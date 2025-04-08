class Solution {
public:
    // LC #3479
    // sqrt decomposition
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int bucket_sz = ceil(sqrt(n)); 

        vector<list<pair<int, int>>> buckets(bucket_sz);

        for (int i = 0; i < baskets.size(); ++i) {
            int bucket_idx = i / bucket_sz;
            buckets[bucket_idx].push_back({baskets[i], i});
        }

        for (auto &bucket : buckets) bucket.sort();

        int ans = 0;

        for (auto fruit : fruits) {
            bool flag = false;

            for (auto &bucket : buckets) {
                if (bucket.back().first >= fruit) {
                    auto m = --bucket.end();
                    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                        if (it->first >= fruit && it->second < m->second) {
                            m = it;
                        }
                    }
                    bucket.erase(m);
                    flag = true;
                    break;
                }
            }

            if (!flag) ++ans;
        }

        return ans;
    }
};
