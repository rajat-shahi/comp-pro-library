#include<bits/stdc++.h>
using namespace std;

#include"monotonic-deque.h"

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		monotonicDeque<int> mdq;
		mdq.clear();

		for (int i = 0; i < k; i++)
		{
			mdq.insertMaxVal(i, v);
		}

		cout << mdq.getMaxVal(v) << " ";

		for (int i = k; i < n; i++)
		{
			// mdq.print();
			mdq.removeMaxInd(i - k);
			mdq.insertMaxVal(i, v);
			cout << mdq.getMaxVal(v) << " ";
		}

		cout << endl;
	}
}