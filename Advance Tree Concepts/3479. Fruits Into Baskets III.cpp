/*
Idea:
Each fruit must go into the leftmost basket whose capacity ≥ fruit.
Once a basket is used, it cannot be reused.
Brute force is slow, so we use a segment tree.

Segment Tree Meaning:
Each node stores the maximum basket capacity in its range.
Helps quickly check if a fruit can fit in any basket.

Steps:

Build Tree
Leaf → basket capacity
Internal node → max(left, right)
Place a Fruit (rmq)
If stree[i] < fruit → cannot place
If leaf → place fruit and mark basket as used (-1)
Always try left child first to get leftmost basket
Update parent after placement

Main Logic
For each fruit, try placing it using the segment tree
If not possible → count as unplaced

Why It Works:
Each placement takes O(log n)
Total time: O(n log n)
Key Insight:
👉 Segment tree lets us efficiently find and reserve the leftmost valid basket.
*/



class Solution {
public:
    void build(int i, int l, int r, vector<int>& stree, vector<int>& basket) {
        if (l == r) {
            stree[i] = basket[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, stree, basket);
        build(2 * i + 2, mid + 1, r, stree, basket);
        stree[i] = max(stree[2 * i + 1], stree[2 * i + 2]);
    }

    bool rmq(int i, int l, int r, vector<int>& stree, int fruit) {
        // if the stree[i]<fruit return false
        if (stree[i] < fruit)
            return false;

        if (l == r) {
            stree[i] = -1; // basket assigned
            return true;
        }
        int mid = l + (r - l) / 2;

        bool placed = false;
        // check whether we can go left side or not
        if (stree[2 * i + 1] >= fruit) {
            placed = rmq(2 * i + 1, l, mid, stree, fruit);
        } else {
            placed = rmq(2 * i + 2, mid + 1, r, stree, fruit);
        }

        // updating the values
        stree[i] = max(stree[2 * i + 1], stree[2 * i + 2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> stree(4 * n, -1);
        build(0, 0, n - 1, stree, baskets);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int f = fruits[i];
            if (!rmq(0, 0, n - 1, stree, f)) {
                cnt++;
            }
        }
        return cnt;
    }
};