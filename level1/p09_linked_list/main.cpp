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
		if (p == t) return;
		Reverse(p -> nex);
		p -> nex -> nex = p;
	}
	
	inline int Find_5(unit *p, int i)
	{
		while (p != t)
		{
			if (i && p -> val == 5) return i;
			p = p -> nex, ++i;
		}
		return -1;
	}

	inline void Insert(unit *p, int i, int val)
	{
		if (i > 1) return Insert(p -> nex, i - 1, val);
		unit *q = new unit {val, null};
		q -> nex = p -> nex;
		p -> nex = q;
	}

	public :
	inline Linked_list()
	{
		null = new unit {0, 0};
		null -> nex = null;
		h = new unit {0, null};
		t = new unit {0, null};
		h -> nex = t;
	}

	inline void Insert(int i, int val)
	{
		Insert(h, i, val);
	}
	
	inline void Reverse()
	{
		Reverse(h);
		h -> nex = null;
		swap(h, t);
	}

	inline int Find_5()
	{
		return Find_5(h, 0);
	}

	inline int Find_nex_5(int i)
	{
		return Find_5(h, -i) + i;
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	// Linked_list lst;
	// lst.Insert(1, 1);
	// lst.Insert(2, 2);
	// lst.Insert(3, 3);
	// lst.Insert(4, 4);
	// lst.Insert(5, 5);
	// lst.Insert(6, 1);
	// lst.Insert(7, 5);
	// cout << lst.Find_5() << '\n';
	// cout << lst.Find_nex_5(lst.Find_5()) << '\n';
	// lst.Reverse();
	// cout << lst.Find_5() << '\n';
	// cout << lst.Find_nex_5(lst.Find_5()) << '\n';

    return 0;
}