#include "push_boxed.h"
#include <string.h>

extern int mp1[30][30], mp2[30][30];
extern int score, stx, sty, n, m, box;

int M1[30][30] =
{
	{0, 0, 0, 1, 1, 1, 0},
	{0, 1, 1, 1, 2, 1, 0},
	{0, 1, 2, 0, 0, 1, 1},
	{1, 1, 1, 0, 0, 2, 1},
	{1, 2, 0, 0, 1, 1, 1},
	{1, 1, 0, 2, 1, 0, 0},
	{0, 1, 2, 1, 1, 0, 0},
	{0, 1, 1, 1, 0, 0, 0}
};

int M2[30][30] =
{
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 2, 1, 0, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};


void init1()
{
	score = 0, box = 6;
	stx = 3, sty = 3;
	n = 8, m = 7;
	memcpy(mp1, M1, sizeof M1);
	memcpy(mp2, M2, sizeof M2);
}

/*
   ### 
 ###O# 
 #OXX##
###*XO#
#OXX###
##XO#  
 #O##  
 ###   
*/