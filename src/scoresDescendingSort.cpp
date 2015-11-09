/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void swap(struct student* a, struct student* b){
	
	struct student temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}
void stringCopy(char* string1, char* string2){

	int index = 0;
	while (string1[index] != '\0'){
		string2[index] = string1[index];
		index++;
	}
	string2[index] = '\0';
}


void qSort(struct student* numbers, int leftIndex, int rightIndex){
	
	int leftHold  = leftIndex;
	int rightHold = rightIndex;
	int midIndex  = (leftIndex + rightIndex) / 2;
	
	swap(&numbers[leftIndex], &numbers[midIndex]);
	
	int pivotIndex;
	int pivot = numbers[leftIndex].score;
	char temp[10];
	stringCopy(numbers[leftIndex].name, temp);
	
	
	while(leftIndex < rightIndex){
		while( numbers[rightIndex].score <= pivot && leftIndex < rightIndex )
			--rightIndex;
		if(leftIndex != rightIndex){
			stringCopy(numbers[rightIndex].name,numbers[leftIndex].name);
			numbers[leftIndex].score = numbers[rightIndex].score;
			leftIndex++;
		}	
		while(numbers[leftIndex].score >= pivot && leftIndex < rightIndex )	
			++leftIndex;
		if(leftIndex != rightIndex){

			stringCopy(numbers[leftIndex].name,numbers[rightIndex].name);
			numbers[rightIndex].score = numbers[leftIndex].score;
			rightIndex--;
		}
	}
	
	numbers[leftIndex].score = pivot;
	stringCopy(temp, numbers[leftIndex].name);

	pivotIndex = leftIndex;
	if(leftHold < pivotIndex)
		qSort(numbers ,leftHold, pivotIndex - 1);
	if(rightHold > pivotIndex)
		qSort(numbers , pivotIndex + 1, rightHold);	
}
void * scoresDescendingSort(struct student *students, int len) {

	if(students == NULL || len < 1)
		return NULL;
		
	qSort(students, 0, len-1);

	return students;
}