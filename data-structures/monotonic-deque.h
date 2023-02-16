/*
	if you are using any function with :
	'Value' at end of it -> give vector as argument too.
*/
template<typename T>
struct monotonicDeque
{
	deque<T> dq;
	monotonicDeque() {}

	void clear()
	{
		dq.clear();
	}

	void insertMaxVal(int ind, vector<T>& v)
	{
		while (not dq.empty() and v[dq.back()] <= v[ind])
		{
			dq.pop_back();
		}
		dq.push_back(ind);
	}

	void insertMinVal(int ind, vector<T>& v)
	{
		while (not dq.empty() and v[dq.back()] >= v[ind])
		{
			dq.pop_back();
		}
		dq.push_back(ind);
	}

	void removeMaxInd(int ind)
	{
		if ((int)dq.size() > 0 and dq.front() == ind)
		{
			dq.pop_front();
		}
	}

	void removeMinInd(int ind)
	{
		if ((int)dq.size() > 0 and dq.front() == ind)
		{
			dq.pop_front();
		}
	}

	int getSize()
	{
		return (int)dq.size();
	}

	T getMaxInd()
	{
		if (dq.empty()) return -1;
		else return dq.front();
	}

	T getMinInd()
	{
		if (dq.empty()) return -1;
		else return dq.front();
	}

	T getMaxVal(vector<T>& v)
	{
		if (dq.empty()) return -1;
		else return v[dq.front()];
	}

	T getMinVal(vector<T>& v)
	{
		if (dq.empty()) return -1;
		else return v[dq.front()];
	}

	void print()
	{
		cout << "Monotonic Deque : " << endl;
		for (auto && i : dq)
		{
			cout << i << " ";
		}
		cout << endl;
	}
};