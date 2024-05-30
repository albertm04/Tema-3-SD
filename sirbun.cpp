#include <bits/stdc++.h>
using namespace std;
ifstream inFile("sirbun.in");
ofstream outFile("sirbun.out");
const int SIZE = 100002;
int n, elements[SIZE];
int segmentTree[4 * SIZE], lazyUpdate[4 * SIZE];

void propagate(int x, int y, int increment, int idx, int start, int end) {
    if (y < start || end < x)
        return;
    if (lazyUpdate[idx] != 0) {
        segmentTree[idx] += lazyUpdate[idx];
        if (start != end) {
            lazyUpdate[idx * 2] += lazyUpdate[idx];
            lazyUpdate[idx * 2 + 1] += lazyUpdate[idx];
        }
        lazyUpdate[idx] = 0;
    }
    if (x <= start && end <= y) {
        segmentTree[idx] += increment;
        if (start != end) {
            lazyUpdate[idx * 2] += increment;
            lazyUpdate[idx * 2 + 1] += increment;
        }
        return;
    }

    int mid = (start + end) / 2;
    propagate(x, y, increment, 2 * idx, start, mid);
    propagate(x, y, increment, 2 * idx + 1, mid + 1, end);

    segmentTree[idx] = min(segmentTree[2 * idx] + lazyUpdate[2 * idx], segmentTree[2 * idx + 1] + lazyUpdate[2 * idx + 1]);
}

int getMin(int x, int y, int additional = 0, int idx = 1, int start = 1, int end = n) {
    if (y < start || end < x)
        return INT_MAX;
    additional += lazyUpdate[idx];
    if (x <= start && end <= y)
        return additional + segmentTree[idx];
    int mid = (start + end) / 2;
    return min(getMin(x, y, additional, 2 * idx, start, mid), getMin(x, y, additional, 2 * idx + 1, mid + 1, end));
}

int main() {
    inFile >> n;
    for (int i = 1; i <= n; i++) {
        inFile >> elements[i];
        propagate(i, i, i, 1, 1, n);
    }
    int first = 1;
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        propagate(elements[i], n, -1, 1, 1, n);
        while (getMin(1, n) < 0 && first < i) {
            propagate(elements[first], n, 1, 1, 1, n);
            first++;
        }
        result += (i - first + 1);
    }
    outFile << result;
    return 0;
}

