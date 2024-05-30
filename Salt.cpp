#include <bits/stdc++.h>
using namespace std;

int main() {

    const int MODULO = 1e9 + 7;

    int numarElemente;
    cin >> numarElemente;

    vector<int> exponentBinarPentruIndex(numarElemente + 1), puteriDeDoiModulo(numarElemente + 1);
    exponentBinarPentruIndex[1] = 0;
    puteriDeDoiModulo[0] = 1;
    puteriDeDoiModulo[1] = 2;

    // Prelucrarea preliminară a puterilor lui 2 și a modulilor lor
    for (int i = 2; i <= numarElemente; i++) {
        exponentBinarPentruIndex[i] = 1 + exponentBinarPentruIndex[i >> 1];
        puteriDeDoiModulo[i] = (puteriDeDoiModulo[i - 1] << 1) % MODULO;
    }

    int inaltimeRMQ = exponentBinarPentruIndex[numarElemente] + 1;

    vector<vector<int>> interogareMaximPeRaza(inaltimeRMQ + 1, vector<int>(numarElemente + 1));

    // Citirea elementelor array-ului
    for (int i = 1; i <= numarElemente; i++)
        cin >> interogareMaximPeRaza[0][i];

    // Construirea tabelului RMQ pentru interogarea maximului pe raza
    for (int nivel = 1; nivel <= inaltimeRMQ; nivel++) {
        for (int i = 1; i <= numarElemente; i++) {
            interogareMaximPeRaza[nivel][i] = interogareMaximPeRaza[nivel - 1][i];
            int indexUrmator = i + (1 << (nivel - 1));
            if (indexUrmator <= numarElemente) {
                interogareMaximPeRaza[nivel][i] = max(interogareMaximPeRaza[nivel][i], interogareMaximPeRaza[nivel - 1][indexUrmator]);
            }
        }
    }

    int numarInterogari;
    cin >> numarInterogari;
    for (int j = 1; j <= numarInterogari; j++) {
        int stanga, dreapta;
        cin >> stanga >> dreapta;

        int lungimeInterval = dreapta - stanga + 1;
        int nivel = exponentBinarPentruIndex[lungimeInterval];
        int interval = (1 << nivel);

        int elementMaxim = max(interogareMaximPeRaza[nivel][stanga], interogareMaximPeRaza[nivel][dreapta - interval + 1]);

        // Afișarea elementului maxim înmulțit cu 2^(lungimeInterval-1) % MODULO
        cout << 1LL * elementMaxim * puteriDeDoiModulo[lungimeInterval - 1] % MODULO << '\n';
    }
    return 0;
}

