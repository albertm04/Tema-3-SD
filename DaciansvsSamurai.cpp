#include <bits/stdc++.h>
using namespace std;
const int MAX_DIM = 100002;

struct Element {
    int x, y;
} elements[MAX_DIM];

inline bool compareElements(const Element &e1, const Element &e2) {
    if (e1.x == e2.x)
        return e1.y < e2.y;
    return e1.x < e2.x;
}

int main() {
    int count;
    cin >> count;
    for (int i = 1; i <= count; i++) {
        cin >> elements[i].x >> elements[i].y;
        if (elements[i].x > elements[i].y)
            swap(elements[i].x, elements[i].y);
    }
    sort(elements + 1, elements + count + 1, compareElements);
    int result = elements[count].x - elements[1].x, lowest = INT_MAX, highest = INT_MIN;

    for (int i = 1; i < count; i++) {
        if (elements[i].y > highest)
            highest = elements[i].y;
        if (elements[i].y < lowest)
            lowest = elements[i].y;
        int currentMax = max(highest, elements[count].x);
        int currentMin = min(lowest, elements[i + 1].x);
        result = min(result, currentMax - currentMin);
    }


    if (elements[count].y > highest)
        highest = elements[count].y;
    if (elements[count].y < lowest)
        lowest = elements[count].y;
    result = min(result, highest - lowest);
    cout << result;
    return 0;
}

