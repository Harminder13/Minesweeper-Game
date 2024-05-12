// MineSweeper Game

//Include Libraries
#include <stdio.h>
#include <stdlib.h>

// Functions that will be used in the program
void creatMineField(void);
void printGrid();
void guess(void);
int findMines(int row, int column);
void flag(int row, int col);
int check (int row, int col);
int checkWin();
int checkLose();

// Global integers and char variables that will be used in the program
int match=0,minesTotal=10,mines=0,mineField[10][10],emptyMineField[10][10],x,y,M=10,N=10,previous,nearbyMines=0;
char charInput;

// Main function
int main() {
    creatMineField();
    guess();
}

// Function that generates the minefield
void creatMineField(void) {

    // Creating variables for this function
    int i,j;

    // For loop to add the '*' into the both the 10x10 boards
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            mineField[i][j] = '*';
            emptyMineField[i][j] = mineField[i][j];
        }
    }

    // Setting mines to zero, creating srand function with a seed of 2
    mines=0;
    srand(2);
    previous=-1;

    // For loop adds the 10 random mines into the minefield
    for (mines = 0; mines < minesTotal; mines++) {

        // Generates random values for j and i between 0-9 with the minimum values being 0
        j = rand()%10+0;
        i = rand()%10+0;

        // If statement checks to see if the new random values are similar to the previous random values
        // and if true it adds one to mineTotal so a new and unique pair of coordinates can be generated
        if(mineField[i][j]==previous){
            minesTotal++;
        }

        // If statement checks to see if a cell does not have a 'M' if true it adds a 'M' to the randomly generated
        // coordinate
        if (mineField[i][j] != 'M') {
            mineField[i][j] ='M';
            previous=(int)mineField[i][j];
        }
    }

    // For loop checks all adjacent cells
    for (j = 0; j <10; j++) {
        for (i = 0; i < 10; i++) {

            // Checks to see if the current coordinates have a 'M'. If true minefield will equal 0
            if( mineField[i][j] !='M'){
                mineField[i][j]=0;
            }

            // Check the top left cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i-1][j-1] =='M') && (mineField[i][j] != 'M') ){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i-1>=0 && j-1>=0) {
                    mineField[i][j]++;
                }
            }

            // Check the left cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i-1][j] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i-1>=0 && j>=0 && i-1<=9 && j<=9 ) {
                    mineField[i][j]++;
                }
            }

            // Check the top cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i][j-1] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i>=0 && j-1>=0 && i<=9 && j-1<=9 ) {
                    mineField[i][j]++;
                }
            }

            // Check the bottom left cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i-1][j+1] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i-1>=0 && j+1>=0 && i-1<=9 && j+1<=9) {
                    mineField[i][j]++;
                }
            }

            // Check the top left cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i+1][j-1] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i+1>=0 && j-1>=0 && i+1<=9 && j-1<=9) {
                    mineField[i][j]++;
                }
            }

            // Check the right cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i+1][j] == 'M') && (mineField[i][j] != 'M')){ //Right

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i+1>=0 && j>=0 && i+1<=9 && j<=9) {
                    mineField[i][j]++;
                }
            }

            // Check the bottom cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i][j+1] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i>=0 && j+1>=0 && i<=9 && j+1<=9) {
                    mineField[i][j]++;
                }
            }

            // Check the bottom left cell. If it equals 'M' and the current coordinated does not equal 'M' add 1 to
            // the minefield
            if((mineField[i+1][j+1] == 'M') && (mineField[i][j] != 'M')){

                //If statement checks to see if the boards is out of bounds if it is not the following is done
                if(i+1>=0 && j+1>=0 && i+1<=9 && j+1<=9) {
                    mineField[i][j]++;
                }
            }
        }
    }
}

// Void function that outputs the grid
void printGrid(){

    // Creating variables for this function
    int i,j;

    // Calling flag function
    flag(x, y);

    printf("\n");

    // For loop that loops through the entire 10x10 board and prints the boards to the console
    for(j=0;j<M;j++){
        for(i=0;i<M;i++){

            // If emptyMineFiled is equal to '*' then the character and emptyMineField at index i and j are printed
            if( emptyMineField[i][j] == '*'){
                printf("%3c",emptyMineField[i][j]);
            }

                // Else if the mineFiled is equal to 0 then emptyMineFiled at index i and j is made to equal '0' and then
                // the character are printed out
            else if( mineField[i][j] == 0 ){
                emptyMineField[i][j] = '0';
                printf("%3c", emptyMineField[i][j]);
            }

                // Else if CharInput is f and the emptyMineFiled does not equal 1, 2, and 3 the character of emptyMineField
                // are printed at index i and j
            else if (charInput=='f' && emptyMineField[i][j]!=1 && emptyMineField[i][j]!=2 && emptyMineField[i][j]!=3  ){
                printf("%3c", emptyMineField[i][j]);
            }

                // Else if mineFiled equal 'M' then the character of emptyMineFiled at index i and j are printed
            else if(mineField[i][j]=='M'){
                printf("%3c", emptyMineField[i][j]);
            }

                // If the other statements come out to false do the following
            else{

                // Checks to see if emptyMineFiled is equal to 'F' if it is true then the character
                // of emptyMineFiled  at index i and j are printed and then the program continues
                if(emptyMineField[i][j]=='F'){
                    printf("%3c", emptyMineField[i][j]);
                    continue;
                }

                    // if the above statement if false the integers are of emptyMineFiled at index i and j are printed
                else {
                    printf("%3d", emptyMineField[i][j]);
                }
            }
        }
        printf("\n");
    }
}

// Void function that takes AI(player) input/guess
void guess(void) {

    // Creating variables for this function
    int i,j;

    // Calls printGrid function
    printGrid();

    // For loop that counts how many empty cells are left of the board
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {

            // If emptyMineFiled equal '*' or 'F' then 1 is added to match
            if (emptyMineField[i][j]=='*' || emptyMineField[i][j]=='F') {
                match++;
            }
        }
    }

    // Set match to equal zero
    match=0;

    //Prints to the users to enter a command, row, anc column
    printf("Enter \'c\' for check cell, \'f\' for flag cell.\n\nEnter command & cell row col:");

    // Scans the users input
    scanf("%c %d %d",&charInput,&y, &x);

    // If statement checks to see if mineFiled is equal to 'M' and charInput (command from user) is equal to 'f'
    // and if true the guess() function is run again
    if (mineField[x][y] == 'M' && charInput=='f') {
        guess();
    }

        // Checks to see if the user had won the game or not
    else if(mineField[x][y]=='M' && emptyMineField[x][y]!='F'){

        //Call checkWin() and checkLose function
        checkWin();
        checkLose();
    }

        // If the other statements are false then the check and guess function are run
    else {
        check(x,y);
        guess();
    }
}

// Void function that takes in 2 integers row and col. This function flags a cell
void flag(int row, int col){

    // If this is true then add 'F' to emptyMineFiled at index row and col
    if ((charInput=='f' && emptyMineField[x][y]=='*' ) || (charInput=='f' && emptyMineField[x][y]=='M')){
        emptyMineField[row][col]='F';
    }
}

// Function checks if the AI(player) has lost
int checkLose(){
    // If the statement is true the current mineField is printed, the location of the mine is revealed, a message is
    // printed saying the game is over, and the program is closed
    if (mineField[x][y] == 'M' && emptyMineField[x][y]!='F' ) {
        emptyMineField[x][y] = mineField[x][y];
        printGrid();
        printf("You hit a mine, game over.");
        exit(0);
    }
    return(1);
}

// Function checks if the AI(player) has won
int checkWin() {

    // If match equals 10 (meaning there are 10 empty cells left) then a message saying the AI(player) won and the
    // program is closed
    if (match == 10) {
        printf("Congratulations! You win!");
        exit(0);
    }
    return(1);
}

//Function that takes in 2 integer values row and column
int findMines(int row, int column){

    // Variable for this function
    int counter = 0;

    // Checks to see if the cell in not out of bounds
    if (column>=0 && row-1>=0) {

        // Check the cell above
        if (mineField[row- 1][column] == 'M')
            counter++;
    }

    // Checks the cell below
    if(mineField[row + 1][ column] == 'M')
        counter++;

    // Checks the cell to the left
    if(mineField[row][ column - 1] == 'M')
        counter++;

    // Checks the cell to the right
    if(mineField[row][ column + 1] == 'M')
        counter++;

    // Checks to see if the cell is out of bounds
    if (column+1>=0 && row-1>=0) {

        // Checks the top right cell
        if (mineField[row - 1][column + 1] == 'M')
            counter++;
    }

    // Checks to see if the cell is out of bounds
    if (column-1>=0 && row-1>=0) {

        // Checks the top left cell
         if (mineField[row - 1][column - 1] == 'M')
            counter++;
    }

    // Check the bottom right cell
    if (mineField[row + 1][column + 1] == 'M')
        counter++;

    // Check the bottom left cell
    if (mineField[row + 1][column - 1] == 'M')
        counter++;

    // Returns counter
    return counter;
}

//Function that takes in 2 integers row and col and checks the cell from the coordinated provided by the AI(Player)
int check (int col, int row) {

    // If charInput in equal to 'c' the following is run
    if (charInput == 'c') {

        // Sets nearbyMine to 0
        nearbyMines = 0;

        if (row < 0 || row >= 10 || col < 0 || col >= 10 || emptyMineField[col][row] != '*') {
            return 0;
        }

        // Sets nearbyMines to the values from the function findMines
        nearbyMines = findMines(col, row);
        emptyMineField[col][row] = nearbyMines;

        // Checks to see if nearbyMines is less than 1. Also, checks to see if there are 0's around the current coordinates
        // if there are then the all adjacent cells of that coordinate are revealed(keeps going until there are no more 0's
        // adjacent to that cell)
        if (nearbyMines < 1) {

            // Check to see if the cell is out of bounds
            if (col >= 0 && row - 1 >= 0) {

                // Checks top cell
                check(col, row - 1);
            }

            // Checks to see if the cell is out of bounds
            if (col + 1 >= 0 && row - 1 >= 0) {

                // Check top right cell
                check(col + 1, row - 1);
            }

            // Checks right cell
            check(col + 1, row);

            // Checks bottom right cell
            check(col + 1, row + 1);

            // Checks bottom cell
            check(col, row + 1);

            // Checks bottom left cell
            check(col - 1, row + 1);

            // Checks left cell
            check(col - 1, row);

            // Checks to see if coordinates are out of bounds
            if (col - 1 >= 0 && row - 1 >= 0) {

                // Checks top left cell
                check(col - 1, row - 1);
            }
        }
    }
    return(1);
}