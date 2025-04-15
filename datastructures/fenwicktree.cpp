// 1-based indexing
// Binary Indexed Tree (BIT)
//
// Two's complement: -x : flip all bits and add 1
//              flip       add 1
//    e.g. 1010 ----> 0101 ----> 0110
// Thus, x & -x extracts the last set bit
//    e.g. 1010 & 0110 = 0010
// Adding last set bit moves down the tree
// Subtracting last set bit moves up the tree
//
// Idea: prefix sum arrays allow you to answer queries in O(1) time
//       but updating an element takes O(n) in worst case to recompute prefix sums
//
//       imagine you store two separate prefix sum arrays
//       one for the first half and one for the second half
//       updating prefix sums takes O(n/2) time (still O(n)) and answering
//       queries takes O(2) time
//
//       now instead of two prefix sum arrays, store n arrays
//
//       if first bit is set, store value (bottom layer of tree)
//       if second bit is set, store 2 values
//       if third bit is set, store 4 values
//       ...
//       
//       Notice, that n/2 values will have first bit set
//
// Both operations take O(log(n)) time
// delta is the change in arr[i]
class FenwickTree {
private:
    vector<int> bit;

public:
    FenwickTree(int n) : bit(n + 1, 0) {}

    void update(int i, int delta) {
        ++i;
        while (i < bit.size()) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        ++i;
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};
