#include <bits/stdc++.h>
using namespace std;

ifstream fin("kami.in");
ofstream fout("kami.out");

const int MAX_N = 100002; // Dimensiunea maximă a vectorului

int main() {
    int n, a[MAX_N], m, op, index, value, queryParam;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }

    fin >> m;
    a[0] = 1e9;

    while (m--) {
        fin >> op; // Citirea tipului de operație
        if (op) {
            fin >> queryParam; // Citirea parametrului pentru query
            long long sum = 0;
            int level = queryParam;

            // Calcularea sumei până când condițiile sunt îndeplinite
            while (level && sum + a[level] > a[level - 1] && sum <= 1e9) {
                sum += a[level--];
            }

            if (sum > 1e9) { // Dacă suma depășește limita maximă, resetăm nivelul
                level = 1;
            }

            fout << level - 1 << "\n"; // Scrierea rezultatului
        } else {
            // Operație de actualizare a valorilor
            fin >> index >> value;
            a[index] = value; // Actualizarea valorii la indexul specificat
        }
    }

    return 0;
}
