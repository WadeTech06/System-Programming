/*
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #1
* Description: display the max and min from a collection of input values
*/

#include <stdio.h>

// Main func - prompts user to input a value until a 0 is given.
// after the program displays the largest number and smallest
int main()
{
	int temp, max = 0, min = 0, count = 0;
	printf("Enter a number, enter 0 to quit: ");
	scanf("%d", &temp);
	min = temp;
	while (temp != 0)
	{
		if (temp > max)
		{
			max = temp;
		}
		if (temp < min)
		{
			min = temp;
		}
		printf("Enter a number, enter 0 to quit: ");
		scanf("%d", &temp);
		count++;
	}

	if(count !=0)
	{
		printf("The largest number is %d\n", max);
		printf("The smallest number is %d\n", min);
	}
	return 0;
}
