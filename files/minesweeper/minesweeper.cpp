//Minesweeper

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50




void print_Array(int row, int col, int array[30][30]);
void mine_array(int row,int column);
void select_check(int front_array[30][30],int back_array[30][30]);
void check_neig(int x, int y, int farray[30][30],int barray[30][30]);
void boom(int r, int c,int front_array[30][30],int mine_array[30][30]);
void win();
void play_again();
void blank(int x, int y, int backArray[30][30], int frontArray[30][30],int row , int col);




int main(){
	int x,y;
/*	
	int x= rand()%2;
	printf("%c %c \n",1,'');
*/

//	printf("Enter two numbers for x and y axis");scanf("%d %d",&x,&y);
	
	
	
	
	mine_array(10,10);
	
}



 


void print_Array(int row, int col, int array[30][30]){ //print the input array
	int i, j;
	
	

	for(i=0;i<col;i++){
		printf("\t|%d",i+1);
	}
	
	printf("\n");
	
	for(i=0;i<9*col;i++){
			printf("_");
	}
	
	
	printf("\n");
	
	for(i=0;i<col;i++){
		printf("%d|\t",i+1);
		for(j=0;j<row;j++){
			/*note 
			printing with the char 
			*/
		printf("%c\t ",array[i][j]);
		}
		printf("\n");
	}
}


void mine_array(int row,int col){//the arrays generator 

	int i, j ,cell ;
	int back_array[30][30] ,front_array[30][30],mine_array[30][30];
	srand(time(NULL));
	
	
	//fiiling the back_array with the mines and numbers 
	for(i=0;i<col;i++){
		for(j=0;j<col;j++){
			front_array[i][j]='Ü';
			
			int mine = rand()%8;//8 is the density of mine
			
			if(mine==0){
				back_array[i][j]= 'M';//M meaning the mine
				mine_array[i][j]=back_array[i][j];
			}
			else{
				back_array[i][j]=' ';
			}
		
		}
	}
		//printing the back array for check
		//filling the back array with bomb and cels values
	print_Array(row,col,back_array);
	for(i=0;i<col;i++){
		for(j=0;j<col;j++){//checking the the mine
			
			if(back_array[j][i]!='M')
			{
				if (back_array[j-1][i-1]=='M'){
					cell++;
				}

				if (back_array[j-1][i]=='M'){
					cell++;
					
				}

				if (back_array[j][i-1]=='M'){
					cell++;
					
				}

				if (back_array[j+1][i+1]=='M'){
					cell++;
					
				}

				if (back_array[j+1][i]=='M'){
					cell++;
					
				}
				if (back_array[j][i+1]=='M'){
					cell++;
					
				}
				if (back_array[j-1][i+1]=='M'){
					cell++;
					
				}
				if (back_array[j+1][i-1]=='M'){
					cell++;
					
				}
				back_array[j][i]=cell+'0';
				cell=0;
			}
				
			
	
		}
	}
	
	//printing the front_array
	print_Array(row,col,front_array);
	
	printf("********************\n");
	
	//printing the back array for check
	print_Array(row,col,back_array);
	
	//call the slect_check function
	select_check(front_array,back_array);
	
}


void select_check(int front_array[30][30],int back_array[30][30]){
	int check=0,x,y,cell=0,i,j;
	
	//taking a value from the user and checking the results
		while(check!=1){
			printf("enter two numbers for x and y axis (x 'space' y) ");
			scanf("%d %d",&x,&y);
			
			//x and y value in range
			if(x<11 || y<11 || x>0 || y>0){
			
				x=x-1;
				y=y-1;
				if (back_array[y][x]=='M')
				{
					front_array[y][x]=back_array[y][x];
					printf("KABOOOMM!\n");
					boom(10,10,front_array,back_array);
					play_again();//for asking play again
					break;
					
					
				}
				//the cell values
				else
				{
					if (back_array[y-1][x-1]=='M'){ //1
						cell++;
					}
	
					if (back_array[y-1][x]=='M'){ //2
						cell++;
						
					}
	
					if (back_array[y][x-1]=='M'){ // 3
						cell++;
						
					}
	
					if (back_array[y+1][x+1]=='M'){ //4
						cell++;
						
					}
	
					if (back_array[y+1][x]=='M'){ // 5
						cell++;
						
					}
					if (back_array[y+1][x+1]=='M'){ //6
						cell++;
						
					}
					if (back_array[y-1][x+1]=='M'){// 7
						cell++;
						
					}
					if (back_array[y+1][x-1]=='M'){ //8
						cell++;
						
					}
				}
				blank( x,  y, back_array, front_array, 10 , 10);
				printf("\n-----------------------------------------\n}");
				
				if (cell == 0){//blank cells calculating
					for(i=0;i<3;i++){
						for(j=0;j<3;j++){				
							front_array[y+i-1][x+j-1]=back_array[y+i-1][x+j-1];
						}
					}
						
				//	check_neig(x,y,front_array,back_array);
					
					
				}
				else
				{
				front_array[y][x]= cell +'0';
				}
				print_Array(10,10,front_array);
			}
			else{
				printf("Wrong input, try again\n");
				
			}
			cell=0;
}
		


}
/*
//prototype (not using)
//checking the blank cells
void check_neig(int x, int y, int farray[30][30],int barray[30][30])
{
	if(barray[y-1][x-1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	
	if(barray[y-1][x]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	
	if(barray[y][x-1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	if(barray[y+1][x-1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	if(barray[y-1][x+1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	if(barray[y+1][x]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	if(barray[y][x+1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	if(barray[y+1][x+1]== '0'){
		farray[y-1][x-1]=0;
		check_neig(x-1,y-1,farray,barray);
	}
	print_Array(10,10,farray);
}
*/

void play_again(){
	int ans;
	printf("Would you like to play again(?_?)(Y=1/N=0):");
	scanf("%d",&ans);
	
	//bu bölge ekstradan FLUSH istiyor yazý ile olmaz
	
	if(ans==1){
		//game again
		mine_array(10,10);
		
	}
	else if(ans==0){
		//game over
		printf("See you soon ^_^");
	}
}


//
void boom(int r, int c,int front_array[30][30],int back_array[30][30])
{
	int x,y;
	//loop for print mines
	for(y=0;y<r;y++){
		for(x=0;x<c;x++){
			if(back_array[x][y]=='M'){
				front_array[x][y]= 'X';
			}
		}
	}
	printf("*****************************\n*****************Game Over!******************************\n");
	
	print_Array(10,10,front_array);
	
	
	
}


void blank(int y, int x, int backArray[30][30], int frontArray[30][30],int row , int col)
{
	int i,j,check=0,a,b;
	
	printf("\nprinting first\n");
	print_Array(row, col, backArray);

	//positive side 
	if(backArray[x][y]=='0')
	{
	
		for(i=x;i<row;i++)
		{
			for(j=y; j<col ; j++)
			{
				if(backArray[i][j]!='0')
				{
					check++;//for break for loop
					break;
					
				}
				else{
					frontArray[i][j]=backArray[i][j];
					
					
					for(a=0;a<3;a++){
						for(b=0;b<3;b++){				
							frontArray[y+a-1][x+b-1]=backArray[y+a-1][x+b-1];
						}
				}
				}
			}
			
			if(check==3){
				break;
			}
		}
		
		check=0;
		
		
		//negative side
		for(i=x;i>0;i--)
		{
			for(j=y; j>0 ; j--)
			{
				if(backArray[i][j]!='0')
				{
					check++;//for break for loop
					break;
					
				}
				else{
					frontArray[i][j]=backArray[i][j];
					for(a=0;a<3;a++){
						for(b=0;b<3;b++){				
							frontArray[y+a-1][x+b-1]=backArray[y+a-1][x+b-1];
						}
				}
				}
			}
			
			if(check==3){
				break;
			}
		}
		
		check =0;
		
		//x positeve y negative
		
		for(i=x;i<row;i++)
		{
			for(j=y; j>0 ; j--)
			{
				if(backArray[i][j]!='0')
				{
					check++;//for break for loop
					break;
					
				}
				else{
					frontArray[i][j]=backArray[i][j];
					for(a=0;a<3;a++){
						for(b=0;b<3;b++){				
							frontArray[y+a-1][x+b-1]=backArray[y+a-1][x+b-1];
						}
				}
				}
			}
			
			if(check==3){
				break;
			}
		}
		
		check=0;
		
		//x negtive y positive
		for(i=x;i>0;i--)
		{
			for(j=y; j<col ; j++)
			{
				if(backArray[i+1][j-1]!='0')
				{
					check++;//for break for loop
					break;
					
				}
				else{
					frontArray[i][j]=backArray[i][j];
					for(a=0;a<3;a++){
						for(b=0;b<3;b++){				
							frontArray[y+a-1][x+b-1]=backArray[y+a-1][x+b-1];
						}
				}
				}
			}
			
			if(check==3){
				break;
			}
		}
		
		check=0;
	}
	
	printf("\nprinting balnks\n");
	print_Array(row, col, frontArray);

	
	
	
	//end of function
}
	
	
	

//blank 
/*void blank(int size1, int size2, int back_array[30][30],int front_array[30][30]){
	int i,j,x,y,val,val2;
	i=x;
	j=y;
	while(y!=size1){
		while(x!=size2)
		{
			if(back_array[i][j]==0){
				front_array[i][j]=back_array[i][j];
				i++;
				
				front_array[x][y]=back_array[x][y];
				x--;
				
						
			}
			else{
				break;
			}
		}
		
		j++;
		y--;
		
				
		
	}
	print_Array(10,10,front_array);
	
}

*/
