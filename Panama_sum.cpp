#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegmentTree {
    int total, prefix, suffix, maximum;
};

void initialize(vector<SegmentTree>& tree, int node, int value) {
    tree[node].total = tree[node].maximum = value;
    tree[node].prefix = tree[node].suffix = value;
}

void buildTree(vector<SegmentTree>& tree, int start, int end, int node, int idx, int value) {
    if (start == end) {
        initialize(tree, node, value);
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            buildTree(tree, start, mid, 2 * node, idx, value);
        } else {
            buildTree(tree, mid + 1, end, 2 * node + 1, idx, value);
        }

        tree[node].total = tree[2 * node].total + tree[2 * node + 1].total;
        tree[node].prefix = max(tree[2 * node].prefix, tree[2 * node].total + tree[2 * node + 1].prefix);
        tree[node].suffix = max(tree[2 * node + 1].suffix, tree[2 * node + 1].total + tree[2 * node].suffix);
        tree[node].maximum = max({tree[2 * node].maximum, tree[2 * node + 1].maximum, tree[2 * node].suffix + tree[2 * node + 1].prefix});
    }
}

int prefixSum, maximumSum;

void queryTree(const vector<SegmentTree>& tree, int start, int end, int queryL, int queryR, int node) {
    if (queryL <= start && end <= queryR) {
        maximumSum = max({maximumSum, tree[node].maximum, prefixSum + tree[node].prefix});
        prefixSum = max(prefixSum + tree[node].total, tree[node].suffix);
    } else {
        int mid = (start + end) / 2;
        if (queryL <= mid)
            queryTree(tree, start, mid, queryL, queryR, node * 2);
        if (mid < queryR)
            queryTree(tree, mid + 1, end, queryL, queryR, node * 2 + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, queries;
    cin >> n >> queries;
    vector<SegmentTree> posTree(4 * n + 1), negTree(4 * n + 1);
    for (int i = 1; i <= n; ++i) {
        int number;
        cin >> number;
        if (i & 1) {
            buildTree(posTree, 1, n, 1, i, number);
            buildTree(negTree, 1, n, 1, i, -number);
        } else {
            buildTree(posTree, 1, n, 1, i, -number);
            buildTree(negTree, 1, n, 1, i, number);
        }
    }

    while (queries--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            if (l & 1) {
                buildTree(posTree, 1, n, 1, l, r);
                buildTree(negTree, 1, n, 1, l, -r);
            } else {
                buildTree(posTree, 1, n, 1, l, -r);
                buildTree(negTree, 1, n, 1, l, r);
            }
        } else {
            maximumSum = LLONG_MIN, prefixSum = 0;
            queryTree(posTree, 1, n, l, r, 1);
            int finalMax = maximumSum;

            maximumSum = LLONG_MIN, prefixSum = 0;
            queryTree(negTree, 1, n, l, r, 1);

            cout << max(finalMax, maximumSum) << '\n';
        }
    }
    return 0;
}
