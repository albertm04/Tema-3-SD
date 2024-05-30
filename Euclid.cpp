#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

using namespace std;

long long cmmdc(long long a, long long b) {
    long long rest;
    while (b > 0) {
        rest = a % b;
        a = b, b = rest;
    }
    return a;
}

int main() {
    ifstream fin("euclid.in");
    ofstream fout("euclid.out");

    int numarTeste; fin >> numarTeste;

    for (int t = 0; t < numarTeste; t++) {
        int m, n, h, w; fin >> m >> n >> h >> w;
        vector<vector<int>> matrice(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fin >> matrice[i][j];
            }
        }

        long long maxim = 0;
        for (int i = 0; i <= m - h; i++) {
            for (int j = 0; j <= n - w; j++) {
                long long cmmdcCurent = matrice[i][j];
                for (int k = i; k < i + h && cmmdcCurent > maxim; k++) {
                    for (int l = j; l < j + w && cmmdcCurent > maxim; l++) {
                        cmmdcCurent = cmmdc(cmmdcCurent, 1LL * matrice[k][l]);
                    }
                }
                maxim = max(maxim, cmmdcCurent);
            }
        }

        fout << "Cazul #" << t + 1 << ": " << maxim << '\n';
    }

    return 0;
}
