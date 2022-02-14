// Digits calculator with euclidean function method
#include<stdio.h>

int numDigits(int number){
	
	if(number!=0){
		//calculations
		return 1 + numDigits(number/10);
	}	
		return 0;
}

int main(){
	int num;
	//take a number from the use 
	printf("Enter a number:");
	scanf("%d",&num);
	//display the result
	printf("The number digits of %d is %d",num,numDigits(num));
	return 0;
}
