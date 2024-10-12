#include <bits/stdc++.h>

#define re register
#define Re register
#define i64 long long

using namespace std;

class Linked_list
{
	struct unit
	{
		int val;
		unit *nex;
	}*h, *t, *null;

	inline void Reverse(unit *p)
	{
		if (p -> nex == null) return;
		Reverse(p -> nex);
		p -> nex -> nex = p;
	}
	
	inline unit* Find_5(unit *p)
	{
		p = h;
		while (p != null)
		{
			if (p -> val == 5) return p;
			p = p -> nex;
		}
		return null;
	}

	public :
	inline Linked_list()
	{
		null = new unit {0, 0};
		null -> nex = null;
		h = t = null;
	}

	inline void Insert(int val, int id)
	{
		if (t == null) h = t = new unit {val, null};
		else t -> nex = new unit {val, null}, t = t -> nex;
	}

	inline void Initialize(size_t N)
	{
		for (re int i = 1, x; i <= N; ++i)
			cin >> x, Insert(x, i);
	}
	
	inline void Reverse()
	{
		Reverse(h);
		h -> nex = null;
		swap(h, t);
	}

	inline unit* Find_5()
	{
		return Find_5(h);
	}

	inline unit* Find_nex_5(unit *p)
	{
		return Find_5(p);
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	// Linked_list lst;
	// lst.Initialize(5);
	// cout << lst.Find_5() -> val << '\n';

    return 0;
}