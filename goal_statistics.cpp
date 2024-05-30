#include <iostream>
using namespace std;
const int n = 1e6;

struct Nod {
    int frecventa = 0;
    long long suma = 0;
} arbint[4 * n + 1];

void actualizeaza(int nod, int stanga, int dreapta, long long valoare) {
    if (stanga == dreapta) {
        arbint[nod].suma += valoare;
        arbint[nod].frecventa += 1;
    } else {
        int mijloc = (stanga + dreapta) >> 1;
        if (valoare <= mijloc) {
            actualizeaza(nod << 1, stanga, mijloc, valoare);
        } else {
            actualizeaza(nod << 1 | 1, mijloc + 1, dreapta, valoare);
        }

        arbint[nod].suma = arbint[nod << 1].suma + arbint[nod << 1 | 1].suma;
        arbint[nod].frecventa = arbint[nod << 1].frecventa + arbint[nod << 1 | 1].frecventa;
    }
}

long long interogare(int nod, int stanga, int dreapta, long long valoare) {
    if (stanga == dreapta) {
        if (arbint[nod].frecventa == 0) {
            return 0;
        } else {
            return (arbint[nod].suma / arbint[nod].frecventa) * valoare;
        }
    }

    int mijloc = (stanga + dreapta) >> 1;
    if (valoare >= arbint[nod << 1].frecventa + 1) {
        return arbint[nod << 1].suma + interogare(nod << 1 | 1, mijloc + 1, dreapta, valoare - arbint[nod << 1].frecventa);
    } else {
        return interogare(nod << 1, stanga, mijloc, valoare);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int interogari; cin >> interogari;
    for (int i = 0; i < interogari; i += 1) {
        int tip, valoare; cin >> tip >> valoare;
        if (tip == 1) {
            actualizeaza(1, 1, n, 1LL * valoare);
        } else {
            cout << interogare(1, 1, n, 1LL * valoare) << '\n';
        }
    }
    return 0;
}
