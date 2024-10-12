#include "push_boxed.h"
#include <string.h>

extern int mp1[30][30], mp2[30][30];
extern int score, stx, sty, n, m, box;

int MMM1[30][30] =
{
	{1, 1, 1, 1, 1},
	{1, 2, 0, 0, 1},
	{1, 2, 0, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 0, 2, 1},
	{1, 1, 1, 1, 1},
};

int MMM2[30][30] =
{
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 1, 2, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0}
};

void init3()
{
	score = 0, box = 3;
	stx = 3, sty = 3;
	n = 6, m = 5;
	memcpy(mp1, MMM1, sizeof MMM1);
	memcpy(mp2, MMM2, sizeof MMM2);
}
/*
#####
#O  #
#OX #
# X*#
# XO#
#####
*/