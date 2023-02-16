const long long INF = 1001001001001001001ll;
template<typename T>
struct disjointSegmentsMutliset
{
	multiset<pair<T, T>> mt;
	disjointSegmentsMutliset() {}

	void clear()
	{
		mt.clear();
	}

	void insert(T l, T r)
	{
		auto it = mt.lower_bound({l, -INF});

		if (it != mt.begin())
		{
			it--;

			// the segment which starts before 'l' and ends at or after 'r' completely subsumes me
			if (it->second >= r)
			{
				return;
			}

			// the segment which starts before 'l' ends after 'l'
			if (it->second >= l)
			{
				l = min(l, it->first);
				r = max(r, it->second);
				mt.erase(it);
			}
		}

		it = mt.upper_bound({r, INF}); // find the segment which starts strictly after 'r'

		if (it != mt.begin())
		{
			it--; // starting point <= 'r'
			if (it->second >= r)
			{
				l = min(l, it->first);
				r = max(r, it->second);
				mt.erase(it);
			}
		}

		// delete the lines which starts at 'l' or after that and which are <= 'r'

		while (true)
		{
			it = mt.lower_bound({l, -INF});
			if (it == mt.end()) break;
			if (it != mt.end())
			{
				if (it->first > r)
				{
					break;
				}
				else
				{

					l = min(l, it->first);
					r = max(r, it->second);
					mt.erase(it);
				}
			}
		}

		mt.insert({l, r});

	}

	void print()
	{
		for (auto && i : mt)
		{
			cout << "{ " << i.first << " , " << i.second << " }" << endl;
		}
	}


	int getSize()
	{
		return (int)mt.size();
	}
};
