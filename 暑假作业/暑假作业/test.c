#define row 4
#define col 4
#include<stdio.h>
#include<stdbool.h>
bool FindNum(int num, int(*p)[col])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			if (*(p[i] + j) == num)
				return true;
		}
	}
	return false;
};
int main()
{
	int key = 99;
	bool x;
	int a[row][col] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	x = FindNum(key, a);
	if (x == true)
		printf("Exist\n");
	else
		printf("Nonentity\n");
	return 0;
}