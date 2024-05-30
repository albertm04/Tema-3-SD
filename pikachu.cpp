#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
ifstream cin("pikachu.in");
ofstream cout("pikachu.out");

typedef long long ll;

int n, k;vector<int> v;
int minim = 0, maxim = INT_MIN;

ll val(ll x) {
    ll sum = 0;
    for (int i = 0; i < k; ++i)
        sum += abs(v[i] - x);
    ll minim = sum;
    for (int i = k; i < n; ++i) {
        sum += abs(v[i] - x);
        sum -= abs(v[i - k] - x);
        if (sum < minim)
            minim = sum;
    }
    return minim;
}

int main() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        maxim = max(maxim, v[i]);
    }

    ll st = 0, dr = maxim;
    while (st < dr) {
        ll mij = st + (dr - st) / 2;
        ll val1 = val(mij);
        ll val2 = val(mij + 1);
        if (val1 > val2)
            st = mij + 1;
        else
            dr = mij;
    }
    cout << val(st);

    return 0;
}
