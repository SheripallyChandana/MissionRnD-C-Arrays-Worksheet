/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 1)
		return NULL;


	int left = 0;
	int right = len - 1;
	int temp;
	
	while(Arr[left] < Arr[left + 1] && left <= len - 2)
		++left;
	while(Arr[right - 1] < Arr[right] && right >= 1)
		--right;
	
	temp = Arr[left];
	Arr[left] = Arr[right];
	Arr[right] = temp;

	for (int index = 0; index < len; ++index)
		printf(" %3d", Arr[index]);
	
	return Arr;
}