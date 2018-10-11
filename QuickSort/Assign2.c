/*
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #2
* Description: sorts an array of number from  smallest to largest
*/

#include <stdio.h>

/* Signature for quickSort function */
void quickSort(int arr[], int low, int high);

/* Function to print an array with its elements */
void printArr(int arr[], int size)
{
	for (int x = 0; x <= size; x++)
	{
		printf("element in array index %d: ", x);
		printf("%d\n", arr[x]);
	}
}

/* the main function takes 10 elements and sorts the elements from smallest to
largest */
int main()
{
	int temp = 0, high_counter = 0;
	int sortArray[10] = {};

	printf("Enter value or enter 0 to quit: ");
	scanf("%d", &temp);
	if (temp != 0)
	{
		sortArray[0] = temp;

		for (int loop = 1; loop < 10; loop++)
		{
			printf("Enter value or enter 0 to quit: ");
			scanf("%d", &temp);

			if (temp == 0)
			{
				break;
			}
			else
			{
				sortArray[loop] = temp;
				high_counter++;
			}
		}
		
		quickSort(sortArray, 0, high_counter);
		printArr(sortArray, high_counter);
	}
	else
	{
		printf("No number is given.\n");
	}
	return 0;
}
