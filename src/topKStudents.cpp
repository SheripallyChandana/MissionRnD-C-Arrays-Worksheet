/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char name[20];
	int score;
};

void swapTopK(struct student* a, struct student* b){
	
	struct student temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}
void stringCopyTopK(char* string1, char* string2){

	int index = 0;
	while (string1[index] != '\0'){
		string2[index] = string1[index];
		index++;
	}
	string2[index] = '\0';
}


void qSortTopK(struct student* Arr, int leftIndex, int rightIndex){
	
	int leftHold  = leftIndex;
	int rightHold = rightIndex;
	int midIndex  = (leftIndex + rightIndex) / 2;
	
	swapTopK(&Arr[leftIndex], &Arr[midIndex]);
	
	int pivotIndex;
	int pivot = Arr[leftIndex].score;
	char temp[10];
	stringCopyTopK(Arr[leftIndex].name, temp);
	
	
	while(leftIndex < rightIndex){
		while( Arr[rightIndex].score <= pivot && leftIndex < rightIndex )
			--rightIndex;
		if(leftIndex != rightIndex){
			stringCopyTopK(Arr[rightIndex].name,Arr[leftIndex].name);
			Arr[leftIndex].score = Arr[rightIndex].score;
			leftIndex++;
		}	
		while(Arr[leftIndex].score >= pivot && leftIndex < rightIndex )	
			++leftIndex;
		if(leftIndex != rightIndex){

			stringCopyTopK(Arr[leftIndex].name,Arr[rightIndex].name);
			Arr[rightIndex].score = Arr[leftIndex].score;
			rightIndex--;
		}
	}
	
	Arr[leftIndex].score = pivot;
	stringCopyTopK(temp, Arr[leftIndex].name);

	pivotIndex = leftIndex;
	if(leftHold < pivotIndex)
		qSortTopK(Arr ,leftHold, pivotIndex - 1);
	if(rightHold > pivotIndex)
		qSortTopK(Arr , pivotIndex + 1, rightHold);	
}

struct student ** topKStudents(struct student *students, int len, int K) {

	if(students == NULL || len < 1 || K < 1)
		return NULL;

	struct student** topKStudents = (struct student**)calloc(K, sizeof(struct student*));
	
	qSortTopK(students, 0, len-1);
	
	for(int index = 0; index < K; ++index){
		topKStudents[index] = (struct student*)malloc(sizeof(struct student));
		stringCopyTopK(students[index].name,topKStudents[index]->name);
		topKStudents[index]->score = students[index].score;
	}

	return topKStudents;

}