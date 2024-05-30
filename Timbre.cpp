#include <bits/stdc++.h>
using namespace std;

ifstream fIn("timbre.in");
ofstream fOut("timbre.out");

const int MAX_DIM = 10005;
priority_queue<int, vector<int>, greater<int>> minHeap; // Heap-ul minim pentru costuri
struct Stamp {
    int maxCoverage, price;
} stamps[MAX_DIM];

bool customSort(const Stamp &a, const Stamp &b) {
    return a.maxCoverage > b.maxCoverage; // Sortare descrescătoare după valoarea maxCoverage
}

int main() {
    int numStampsNeeded, numStampsAvailable, stampCoverage, totalCost = 0;
    fIn >> numStampsNeeded >> numStampsAvailable >> stampCoverage;

    for (int i = 1; i <= numStampsAvailable; i++) {
        fIn >> stamps[i].maxCoverage >> stamps[i].price;
    }

    sort(stamps + 1, stamps + numStampsAvailable + 1, customSort); // Sortăm timbrele după maxCoverage

    int currentIndex = 1; // Indexul pentru a itera prin vectorul de timbre
    while (numStampsNeeded > 0) {
        while (currentIndex <= numStampsAvailable && stamps[currentIndex].maxCoverage >= numStampsNeeded) {
            minHeap.push(stamps[currentIndex].price);
            currentIndex++;
        }
        totalCost += minHeap.top(); // Adăugăm costul minim la costul total
        minHeap.pop();

        numStampsNeeded -= stampCoverage; // Reducem numărul de timbre necesare cu capacitatea unei singure achiziții
    }

    fOut << totalCost; // Scriem costul total în fișierul de ieșire
    return 0;
}
