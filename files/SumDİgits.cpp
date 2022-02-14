// Sum Digits
#include<stdio.h>

int sumDigits(int number){
	int sum;
	if(number>0){
	//calculations (Euclidean algorithm)
	sum=number%10;
	return sum + sumDigits(number/10);
}
}

int main(){
	int num;
	//take a number from the use
	printf("Enter a number:");
	scanf("%d",&num);
	//display the result
	printf("The sum of digits of %d is %d",num,sumDigits(num));
	return 0;
}


