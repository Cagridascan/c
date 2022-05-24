//  random sentence generator 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	
	srand(time(NULL));
	
	
	
	
	FILE *cfPtr;
	
	if((cfPtr=fopen("book_2.txt","w"))==NULL){
		printf("Error!");
		
	}//end of if
	
	else {
		
		//definations of the arrays
	
		char article[][20]={"the" , "a" , "one" , "some", "any"};
		char verbs[][20]={"drove" , "jumped" , "ran" , "walked", "skipped"};
		char noun[][20]={"boy" , "girl" , "dog" , "town", "car"};
		char prep[][20]={"to" , "from" , "over" , "under", "on"};
		
	
		
	
		
		int i=0;
		//selecting randomly 
		for(i=0;i<10;i++) {
			fprintf(cfPtr,"%s %s %s %s %s %s\n",article[rand()%5] ,noun[rand()%5],verbs[rand()%5],prep[rand()%5],article[rand()%5],noun[rand()%5]);
			
			
		}
		puts("Done.");
		fclose(cfPtr);
		
	}
}
