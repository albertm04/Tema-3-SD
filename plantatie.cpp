#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int rmq[N][N][20], lg[N];
ifstream in("plantatie.in");
ofstream out("plantatie.out");

int main()
{
    lg[1] = 0;
    for (int i = 2; i <= N - 5; i++)
        lg[i] = lg[i / 2] + 1;
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> rmq[i][j][0];
        }
    }
    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i <= n - (1 << k) + 1; i++)
            for (int j = 1; j <= n - (1 << k) + 1; j++)
                rmq[i][j][k] = max(rmq[i][j][k - 1], max(rmq[i][j + (1 << (k - 1))][k - 1],
                                                       max(rmq[i + (1 << (k - 1))][j][k - 1], rmq[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1])));
    while(m--)
    {
        int a, b, k;
        in >> a >> b >> k;
        int len = lg[k];
        k -= (1 << len);
        out << max(rmq[a][b][len], max(rmq[a + k][b][len], max(rmq[a][b + k][len], rmq[a + k][b + k][len]))) << "\n";
    }
    return 0;
}
