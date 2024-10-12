#include "push_boxed.h"
#include <string.h>

extern int mp1[30][30], mp2[30][30];
extern int score, stx, sty, n, m, box;

int MMMM1[30][30] =
{
	{0, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 2, 1},
	{1, 0, 0, 0, 2, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 1, 1},
	{0, 1, 1, 1, 1, 0}	
};

int MMMM2[30][30] =
{
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 2, 1, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

void init4()
{
	score = 0, box = 2;
	stx = 3, sty = 2;
	n = 6, m = 6;
	memcpy(mp1, MMMM1, sizeof MMMM1);
	memcpy(mp2, MMMM2, sizeof MMMM2);
}
/*
  ####
### O#
# X O#
# *X #
##  ##
 #### 
*/