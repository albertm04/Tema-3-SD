
#include<bits/stdc++.h>
using namespace std;
const int dim = 100002;
int last_pos[dim]; // Ultima pozitie la care apare fiecare element x
int n, first_distinct[dim], min_query[18][dim], max_query[18][dim], log2val[dim], powers_of_two[20];

void precompute() {
    int level = 1, range = 2;
    while (range <= n) {
        for (int i = 1; i <= n - range + 1; i++) {
            min_query[level][i] = min(min_query[level - 1][i], min_query[level - 1][i + range / 2]);
            max_query[level][i] = max(max_query[level - 1][i], max_query[level - 1][i + range / 2]);
        }
        range *= 2;
        level++;
    }
}

int main() {
    int value, queries, start, end;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value;
        min_query[0][i] = value;
        max_query[0][i] = value;
        first_distinct[i] = max(first_distinct[i - 1], last_pos[value] + 1);
        last_pos[value] = i;
    }
    precompute();
    int power = 1, index = 0;
    powers_of_two[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (power * 2 == i) {
            power *= 2;
            ++index;
            powers_of_two[index] = power;
        }
        log2val[i] = index;
    }
    cin >> queries;
    while (queries--) {
        cin >> start >> end;

        int min_range = min(min_query[log2val[end - start + 1]][start], min_query[log2val[end - start + 1]][end - powers_of_two[log2val[end - start + 1]] + 1]);
        int max_range = max(max_query[log2val[end - start + 1]][start], max_query[log2val[end - start + 1]][end - powers_of_two[log2val[end - start + 1]] + 1]);

        if (max_range - min_range == end - start && first_distinct[end] <= start)
            cout << 1;
        else
            cout << 0;
    }
}
