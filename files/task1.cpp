/*
Çaðrý Daþcan 
2019502030
Preliminary 10
*/

//task 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function for fill array
int fillArray(int array[5][5])
{
	//random numbers generetor from 0 to 9
	
	int i,j;
	//5x5 loop for fill array randomly
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			array[i][j]= rand()%10;
		}
	}
	return 0;
}

//display the 5x5 array
int printArray(int array[5][5])
{
	int i,j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
}

//multiple the two array values
int multArray(int multArr[5][5],int arr1[5][5],int arr2[5][5]){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			multArr[i][j]=arr1[i][j]*arr2[i][j];
		
		}
	}
}

//sum two array 
int sumArray(int sumArr[5][5],int arr1[5][5],int arr2[5][5]){
	
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			sumArr[i][j]=arr1[i][j]+arr2[i][j];
		
		}
	}

}

//sum diagonal terms
int sumDiag(int arr1[5][5]){
	int i,j,sum=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i==j){
				sum=sum+arr1[i][j];
			}
		
		}
	}

	return sum;
}

int main(){
	srand(time(NULL));	//for random number
	
	int array1[5][5], array2[5][5],sumArr[5][5];
	//call the fillArray function for fill arrays
	fillArray(array1);
	fillArray(array2);
	
	//display arrays with printArray function 
	printf("The content of the array1 is:\n");
	printArray(array1);
	
	printf("The content of the array2 is:\n");
	printArray(array2);
	
	printf("The sum of array1 and array2 is:\n");
	//call sumArray for sum of arrays
	sumArray(sumArr,array1,array2);
	printArray(sumArr);
	
	//Task 2
	printf("**************- Task 2 -****************************\n");
	
	int array_1[5][5], array_2[5][5],multArr[5][5];
	//call the fillArray function for fill arrays randomly
	fillArray(array_1);
	fillArray(array_2);

	//display arrays with printArray function 
	printf("The content of the array1 is:\n");
	printArray(array_1);
	
	printf("The content of the array2 is:\n");
	printArray(array_2);
	
	//call the multArr for multiple the arrays values
	printf("The multiply of array1 and array2 is:\n");
	multArray(multArr,array_1,array_2);
	printArray(multArr);
	
	//Task 3
	printf("****************- Task 3 -*************************\n");
	
	int array_3[5][5];
	//call the fillArray function for fill array randomly
	fillArray(array_3);
	
	//print the array with printArray function
	printf("The content of the array1 is:\n");
	printArray(array_3);
	
	//Calculate sumDiag for the sum of diagonal term and display
	printf("The multiply of array1 and array2 is: %d\n",sumDiag(array_3));
	
	

	
	return 0;
	
}
