#include<bits/stdc++.h>
using namespace std;
#include"disjoint-segments-multiset.h"

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	disjointSegmentsMutliset<long long> dsmt;
	int q;
	cin >> q;

	for (auto i = 0; i < q; i++)
	{
		char ch;
		cin >> ch;

		if (ch == '+')
		{
			long long l, r;
			cin >> l >> r;
			dsmt.insert(l, r);
		}
		else
		{
			cout << dsmt.getSize() << endl;
		}

		dsmt.print();
	}
}