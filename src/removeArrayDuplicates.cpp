/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
int findBucket(int key, int* numbers, int* hashTable, int bucketSize, int tableSize){
	
	int bucket = key % tableSize;
	bucket = bucket < 0 ? -bucket : bucket;
	int tempBucket = bucket;
	int i;
	
	if(hashTable[bucket] == -1)
		return bucket;
	else		
		for(i = 0; hashTable[bucket] != -1 && tableSize != bucketSize; ++i){
			bucket = (tempBucket + i) % tableSize;
			if(hashTable[bucket] == key)
				return bucket;
		}
		return bucket;	
}

void * removeArrayDuplicates(int *Arr, int len)
{
	if(Arr == NULL || len < 1)
		return NULL;

	int index;
	int bucket;
	int hashTable[30];
	int bucketSize = 0;
	int tempIndex = 0;
	
	for(index = 0; index < len; ++ index)
		hashTable[index] = -1;
	
	for (index = 0; index < len; ++index){
		
		bucket = findBucket(Arr[index], Arr, hashTable, bucketSize, 30);
		if(hashTable[bucket] == Arr[index])
			continue;
		else{		
			hashTable[bucket] = Arr[index];
			Arr[tempIndex++] = Arr[index];
			bucketSize++;
		}
	}
	
	return Arr;
}