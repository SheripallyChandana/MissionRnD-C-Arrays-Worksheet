
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {


	*lessCount = 0;
	*moreCount = 0;
	int leftIndex = 0;
	int rightIndex = len - 1;
	int midIndex;
	
	if(Arr == NULL || len < 1)
		return NULL;
	
	while(leftIndex <= rightIndex){
		midIndex = (leftIndex + rightIndex)/2;

		if(midIndex == leftIndex && leftIndex == rightIndex){
			if(Arr[midIndex] < score)
				*lessCount = 1;
			else if(Arr[midIndex] > score)
				*moreCount = 1;
			break;		
		}
		else if(Arr[midIndex] == score && Arr[midIndex -1] != score && Arr[midIndex +1] != score){
			*lessCount = midIndex;
			*moreCount = len - midIndex - 1;
			break;
		}
		else if(Arr[midIndex - 1] < score && Arr[midIndex] > score){
			*lessCount = midIndex;
			*moreCount = len - midIndex;
			break;
		}	
		else if(Arr[midIndex] < score && Arr[midIndex + 1] > score){
			*lessCount = midIndex + 1;
			*moreCount = len - midIndex - 1;
			break;
		}else if(Arr[midIndex] <= score)
			leftIndex = midIndex + 1;
		else
			rightIndex = midIndex - 1;			
	}
	return 0;	
}
