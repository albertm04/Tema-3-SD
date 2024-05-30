#include <bits/stdc++.h>
using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

const int MAXN=250005;
int p[MAXN], str[18][MAXN];

int main()
{
    int n, m;
    fin>>n>>m;

    for (int i=1; i<=n; ++i)
    {
        int x;
        fin>>x;
        p[i] = x;
    }

    for (int i=1; i<=n; ++i)
        str[0][i] = p[i];
    for (int h=1; h<18; ++h)
        for (int i=1; i<=n; ++i)
            str[h][i] = str[h-1][str[h-1][i]];


    while (m--)
    {
        int q, i;
        fin>>q>>i;

        int curr=q;
        for (int j=0; j<18; ++j)
            if (i&(1<<j))
                curr = str[j][curr];

        fout<<curr<<'\n';
    }
}
