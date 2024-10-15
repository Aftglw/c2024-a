#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node *nex;
};
typedef struct Node node;

void swap(node **x, node **y)
{
	node *z = *x;
	*x = *y, *y = z;
}

node *h, *t, *null;

node* New(int val)
{
	node *tmp = malloc(sizeof (node));
	tmp -> val = val, tmp -> nex = null;
	return tmp;
}

void reverse(node *p)
{
	if (p == t) return;
	reverse(p -> nex);
	p -> nex -> nex = p;
}

int find_5(node *p, int i)
{
	while (p != t)
	{
		if (i && p -> val == 5) return i;
		p = p -> nex, ++i;
	}
	return -1;
}

void insert(node *p, int i, int val)
{
	if (i > 1) return insert(p -> nex, i - 1, val);
	node *q = New(val);
	q -> nex = p -> nex;
	p -> nex = q;
}

void Insert(int i, int val)
{
	insert(h, i, val);
}

void Reverse()
{
	reverse(h);
	h -> nex = null;
	swap(&h, &t);
}

int Find_5()
{
	return find_5(h, 0);
}

int Find_nex_5(int i)
{
	return find_5(h, -i) + i;
}

signed main()
{
	null = malloc(sizeof (node));
	null -> val = 0, null -> nex = null;
	h = New(0), t = New(0);
	h -> nex = t;

	// Insert(1, 1);
	// Insert(2, 2);
	// Insert(3, 3);
	// Insert(4, 4);
	// Insert(5, 5);
	// Insert(6, 1);
	// Insert(7, 5);

	// printf("%d\n%d\n", Find_5(), Find_nex_5(Find_5()));
	// Reverse();
	// printf("%d\n%d\n", Find_5(), Find_nex_5(Find_5()));

	return 0;
}