#include "push_boxed.h"
#include <string.h>

extern int mp1[30][30], mp2[30][30];
extern int score, stx, sty, n, m, box;

int MMMMM1[30][30] =
{
	{1, 1, 1, 1, 1},
	{1, 2, 0, 2, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 2, 0, 2, 1},
	{1, 1, 1, 1, 1}
};
int MMMMM2[30][30] =
{
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 2, 0, 0},
	{0, 0, 0, 0, 0}
};


void init5()
{
	score = 0, box = 4;
	stx = 6, sty = 2;
	n = 8, m = 5;
	memcpy(mp1, MMMMM1, sizeof MMMMM1);
	memcpy(mp2, MMMMM2, sizeof MMMMM2);
}
/*
#####
#O O#
# X #
# X #
# X #
# X #
#O*O#
#####
*/