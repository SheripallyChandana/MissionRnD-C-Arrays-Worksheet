/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{

	if (Arr == NULL || len < 1)
		return NULL;

	printf("\n");
	for (int index = 0; index < len; ++index)
		printf(" %3d", Arr[index]);
	
	Arr = (int*)realloc(Arr, (len +1)* sizeof(int));

	int index = len;
	while(index > 0){
		if(Arr[index - 1] <= num){
			Arr[index] = num;
			break;
		}else
			Arr[index] = Arr[index - 1];
		--index;
	}
	
	if(index == 0)
		Arr[index] = num;
		
	
	printf("\n");
	for (int index = 0; index < len + 1; ++index)
		printf(" %3d", Arr[index]);
	return Arr;
}