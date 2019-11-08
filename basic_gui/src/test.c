#include  <stdio.h>
#include<stdlib.h>
#include"sudoku_solver.h"


int main(){
    int puzzle[9][9] = {
                  6,0,0,	5,0,8, 		0,0,9,
                  0,3,0,	2,0,7,		0,5,0,
                  0,0,8,	0,3,0,		2,0,0,
                  
                  0,6,5,	0,0,0,		8,1,0,
                  8,0,0,	0,0,0,		0,0,3,
                  0,2,4,	0,0,0,		5,9,0,
                  
                  0,0,7,	0,2,0,		1,0,0,
                  0,1,0,	6,0,4,		0,7,0,
                  2,0,0,	7,0,1,		0,0,4
               };
               
     int **malloced_puzzle;
     malloced_puzzle = (int **)malloc(sizeof(int *) * 9);
     
     int i,j;
     
     for(i = 0; i< 9; i++)
	malloced_puzzle[i] = (int *)malloc( sizeof(int) * 9);
	
    for(i = 0; i < 9; i++)
    	for(j = 0; j < 9; j++)
    		malloced_puzzle[i][j] = puzzle[i][j];
     
     
    print_puzzle(malloced_puzzle);
    printf("*****************************\n");
    
    if( solve(malloced_puzzle) ){
        printf("yeah!\n");
        print_puzzle(malloced_puzzle);
    }
    
    else{
         printf("not solveable :( \n");
    }
    
    return 0;
}

