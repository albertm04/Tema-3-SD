#include<bits/stdc++.h>
using namespace std;

const int LIMITA = 100002;
ifstream fin("bleach.in");
ofstream fout("bleach.out");
priority_queue<int, vector<int>, greater<int>> coadaPrioritati;

int main()
{
    int numarElemente, numarK, valoareElement;
    long long costSuplimentar = 0, energieCurenta = 0;
    fin >> numarElemente >> numarK;

    // Citirea elementelor și adăugarea lor într-o coadă de priorități
    for (int i = 1; i <= numarElemente; i++)
    {
        fin >> valoareElement;
        coadaPrioritati.push(valoareElement);
    }

    // Procesarea elementelor din coadă
    while (!coadaPrioritati.empty())
    {
        int elementCurent = coadaPrioritati.top();
        coadaPrioritati.pop();

        // Verificăm dacă avem suficientă energie pentru a procesa elementul curent
        if (elementCurent > energieCurenta)
        {
            costSuplimentar += elementCurent - energieCurenta;
            energieCurenta = elementCurent;
        }
        energieCurenta += elementCurent;
    }

    fout << costSuplimentar << '\n';
    return 0;
}

