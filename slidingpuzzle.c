#include<stdio.h>
#define boardRow 4
#define boardColumn 4

void move_tile(int row,int col,int new_row,int new_col);
//Initialization of 4x4 Board in Reverse order from 15-1
//The zero represents the empty spot where numbers can move to if they are adjacent.
int board[4][4]={{15, 14, 13, 12},
                 {11, 10, 9, 8},
                 {7, 6, 5, 4,},
                 {3, 2, 1, 0}};

/*
*Initializes the game
*Prints startup message
*/
void initialization(void){

   printf("Setting up the game...\n");
               
}

/*
*Tears Down the Game.
*Prints ending message.
*/
void teardown(void){

   printf("Ending the game.\n");

}

/*
*Prints out the board
*Depending on changes made with user input, board will print
*/
void print(void){
   for(int i = 0; i < boardRow; i++){//Iterates through rows
      for(int j = 0; j < boardColumn; j++){//Iterates through columns
         if(board[i][j]!=0){//Condition for printing all values except zero
            printf("%d\t", board[i][j]);
            
         }
         else{//If the board value is zero, print a empty space instead of a zero.
            printf(" \t");
            
         }  
      
   }

   printf("\n");//Prints a new line after each row
    
   }

}
/*
*Checks whether a tile can be moved
*@param num: tile number to move
*@return 1 if tile is moveable, and 0 if not movable.
*/

int is_move_valid(int num){
    for(int i = 0; i < boardRow; i++){//Iterates through board Rows.
        for(int j = 0; j < boardColumn; j++){//Iterates throgh column rows.
            if(board[i][j]==num){//Creates Condition that allows the change of the board location only if that location's value is equal to the inpputed number.
                if(i - 1 >= 0){//Checks the iteration to see if it has a valid row
                    if(board[i-1][j]==0){//Checks if tile above inputted number is zero.
                        move_tile(i,j,i-1,j);//If true, the inputted number is moved to that position.
                        return 1;//Returns one so that case 'm' does not print invalid move
                    }
                }
                if(i+1<4){//Checks the iteration to see if it has a valid row
                    if(board[i+1][j]==0){//Checks if the tile below the inputted number is zero.
                        move_tile(i,j,i+1,j);//If true, the inputted number is moved to that position.
                        return 1;//Returns one so that case 'm' does not print invalid move
                    }
                }
                if(j-1>=0){//Checks the iteration to see if it has a valid column
                    if(board[i][j-1]==0){//Checks if the tile to the left of the inputted number is zero.
                        move_tile(i,j,i,j-1);//If true, the inputted number is moved to that position.
                        return 1;//Returns one so that case 'm' does not print invalid move
                    }
                }
                if(j+1<4){//Checks the iteration to see if it has a valid column
                    if(board[i][j+1]==0){//Checks if the tile to the right of the inputted number is zero.
                        move_tile(i,j,i,j+1);//If true, the inputted number is moved to that position.
                        return 1;//Returns one so that case 'm' does not print invalid move
                    }
                }
                return 0;//Returning a zero prints "Invald Move" in case 'm'.  A return of zero is a result of not meeting any of the above iterations
            }
        }
    }
    
    return 0;//Returning a zero prints "Invald Move" in case 'm'. A return of zero is a result of not meeting any of the above iterations
            
}
/*
*Moves inputted tile to the "empty" space (represented by a zero).
*@param row: represents the row of the inputted value "num"
*@param col: represents the column of the inputted value "num"
*@param new_row: represents the row of where the inputted value "num" is moving 
*@param new_col: represents the column of where the inputted value "num" is moving
*/
void move_tile(int row,int col,int new_row,int new_col){
    board[new_row][new_col]=board[row][col];//Changes the value of where the zero was to the inputted value.
    board[row][col]=0;//Sets the location of the inputted value to zero.
}

/*
*Accepts input from the user
*Gives user choice of p, m, q
*If any other input is given, an error message is outputed.
*/
int acceptInput(void){
   char userInput;
   int userTile;
   while(userInput != 'q'){//While the user does not type q, the loop continues.
        printf("Options: [p]rint, [m]ove, [q]uit: ");
        scanf(" %c", &userInput);//Scans the user input which should be a char.
        switch(userInput){
            case 'p':
                print();
                printf("\n");
                break;
            case 'm':
            printf("Which tile would you like to move? ");
                scanf("%d",&userTile);//Scans a value for the inputted tile
                if(is_move_valid(userTile)==0)//If is_move_valid return's zero, then print below
                    printf("Invalid Move.\n");
                else
                    printf("Moving %d\n",userTile);
                    
                break;
            case 'q':
               teardown();
               break;
            default://If anything other than p, m, or q is inputted, "Invalid Input" is printed.
               printf("Invalid input.\n");
               break;
                     
        }

   }

}
/*
*Calls the initialization of the game 
*Calls the input loop of the game
*@return 0 means the program executed successfully.
*/
int main(void){

   initialization();//Calls the initalization method.

   acceptInput();//Calls the acceptInput loop.

   return 0;

}
