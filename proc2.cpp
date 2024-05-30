#include <bits/stdc++.h>
using namespace std;
ifstream fin("proc2.in");
ofstream fout("proc2.out");

int main()
{
    priority_queue <int> pq;
	priority_queue <pair<int,int>> pq2;
	int n, m, s, d;

	fin >> n >> m;

	for (int i = 1; i <= n; i++)
		pq.push(-i);

	for (int i = 0; i < m; i++)
	{
		fin >> s >> d;
		s = - s;
		while (!pq2.empty() && pq2.top().first >= s)
		{
			pq.push(-pq2.top().second);
			pq2.pop();
		}
		pq2.push({ s - d, -pq.top()});
		fout << -pq.top() << '\n';
		pq.pop();
	}
	return 0;
}
