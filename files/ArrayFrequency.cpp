//Number freequency in the array  
#include<stdio.h>

int arrayIntegers(int array[10]);
int printArray(int array[10],int size);

//a function for take the number from user for array
int arrayIntegers(int array[5]){
	int i;
	
	//loop from 0 to 9
	for(i=0;i<10;i++){
		
		//take value from user
		printf("Enter a integer. _1 to finish entering elements. %d items reamening:",10-i);
		scanf("%d",&array[i]);
		
		//if the users value is -1 break the loop
		if(array[i]==-1){
			
			//equate array[i] to NULL 
			array[i]=NULL;
			break;
		}
		
	}
	return i;//return the i for size of array
}

//a function for print array
int printArray(int array[10],int size){
	int i;
	//lopp from the 0 to size
	for(i=0;i<size;i++){
		//display the array[i]
		printf("%d  ",array[i]);
	}
	printf("\n");
	
}



int main(){
	int array[10];
	int size1,i,j,k,sum,test=0;
	
	//take number from the user for array
	size1=arrayIntegers(array);
	printf("\nThe content of the array:");
	printArray(array,size1);
	printf("Item\tFrequency\n");
	
	
	for(i=0;i<size1;i++){
		sum=0;
		test=0;
		//a value is how many times repeat 
		for(j=i;j<size1;j++){
		
			
			if(array[i]==array[j]){
				sum++;
			}
		
		}
		for(k=i-1;k>-1;k--){//test for value is repeat before
			if(array[i]==array[k]){
			test=1;
		}
		}
		//test if equal to 0 display the result
		if(test==0){
			printf("%d\t%d\n",array[i],sum);
		}
		
	
		
	}
	
	
	return 0;
}

