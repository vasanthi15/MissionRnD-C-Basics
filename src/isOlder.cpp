/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
int chkLess(int date[3][3])
{
	int i;
	int limit[3] = { 31, 12, 9999 };
	for (i = 0; i < 3; i++)
	{
		if (date[i][0] <= 0 || date[i][1] <= 0 || date[i][1] > limit[i] || date[i][0] > limit[i])
		{
			return -1;
		}
	}
		if (((date[1][0] == 7 || date[1][1] == 7)) && (date[0][0] > 30 || date[0][1] > 31))
			return -1;
	return 0;
}
void initialise(int date[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			date[i][j] = 0;
}
void calc(char *dob1, char *dob2, int date[3][3], int len,int pos)
{
	int i;
	for (i = 0; i <len; i++)
	{
		date[pos][1] = date[pos][1] * 10 + int(*dob2++)-48;
		date[pos][0] = date[pos][0] * 10 + int(*dob1++)-48;
	}
}
int isOlder(char *dob1, char *dob2)
{
	int date[3][3], i;
	initialise(date);
	dob1 += 6;
	dob2 += 6;
	calc(dob1,dob2,date,4,2);
	dob1 -= 3;
	dob2 -= 3;
	calc(dob1, dob2, date, 2,1);
	dob1 -= 3;
	dob2-=3;
	calc(dob1, dob2, date, 2,0);
	if (chkLess(date) == -1)
	{
		return -1;
	}
	for (i = 0; i<2; i++)
		if (date[1][i] == 2)
		{
			if ((date[2][i] % 4 != 0) && (date[0][i])>28)
			{
				return -1;
			}
		}

	if ((date[1][1] == 2) && (date[2][1] % 4 == 0) && (date[0][1] > 29))
	{
		return -1;
	}
	for (i = 0; i<3; i++)
	{
		if (i == 1)
		{
			if (date[i][0] == 2 || date[i][1] == 2)
			{
				if ((date[2][0] % 4 == 0) || (date[2][0] % 4 == 0))
				{
					if (date[0][0] > 29 || date[0][1] > 29)
					{
						return -1;
					}
				}
				else
				{
					if (date[0][0] > 28 || date[0][1] > 28)
					{
						return -1;
					}
				}
			}
			if ((date[i][0] % 2 == 0) && ((date[0][0]>30) || (date[0][1]>30)))
				return -1;
		}
		if (date[i][0]>date[i][1])
			return 2;
		if (date[i][0]<date[i][1])
			return 1;
	}
	return 0;
}


