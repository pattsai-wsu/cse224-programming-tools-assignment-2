// Patrick Tsai - PA2 - CSE 224 10am - DUE 10/18/2019 8am
// 
// STICK GAME - programmed in C
// 1. User selects the # of sticks for initial pile from command line or after initially running program
// 2. User always goes first and may select the number of sticks (1, 2, or 3) to remove from the pile
// 3. After user turn the Computer chooses the number of sticks to take from the stack
// 4. The user and computer continue to take turns till the pile total equals 0
// 5. Displays who won

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int func_usrInput_howMany();
int func_computerTurn(int*, int);
int func_usrTurn(int*, int*);
int func_usrTurnTest(int*, int);
int func_showSticks(int);
void func_checkWinner(int, int);

int main (int argc, char **argv) {

 int illegal_move, round, num, numReturn, returnVal, usrTurnNow, total;
 char cmdLineTemp[120], usrTakeTemp[120], temp[120];

 illegal_move=0;
 round=1;

/* START -  HANDLES THE INPUT FOR INITAL STICK PILE */

  if (argc == 1) {   //     NO command line input given
    numReturn=func_usrInput_howMany();   //  ask user how many sticks to use for the game at the next prompt

    if (numReturn > 9) {            // GOOD ENTRY 
    printf("You chose to play with (%d) sticks\n", numReturn);
    }
    else {
    printf("Invalid Entry\nGOODBYE!\n");
    exit(0);
//    numReturn=func_usrInput_howMany();   //  ask user how many sticks to use for the game at the next prompt
//    printf("You chose to play with <%d> sticks\n", numReturn);
    }
  }

  if (argc == 2) {    //    YES, only ONE command line input given after program declaration

    returnVal=sscanf(argv[1], "%d%s", &num, cmdLineTemp); //convert command line argument  

    if (returnVal != 1 || num < 10) {
    printf("Invalid Entry\nGOODBYE!\n");
    exit(0);
//    numReturn=func_usrInput_howMany();   //  ask user how many sticks to use for the game at the next prompt
//    printf("You chose to play with <%d> sticks\n", numReturn);
    }
    else if (returnVal == 1 && num > 9) {            // GOOD ENTRY
    numReturn=num; 
    printf("You chose to play with (%d) sticks\n", numReturn);
    }
  }

  if (argc > 2) {   //     NO command line input given
    printf("Invalid Entry\nGOODBYE\n");
    exit(0);
//    numReturn=func_usrInput_howMany();   //  ask user how many sticks to use for the game at the next prompt
//    printf("You chose to play with <%d> sticks\n", numReturn);

  } 

/* END -  HANDLES THE INPUT FOR INITAL STICK PILE */


/* START ---- MAIN TURN HANDLING ---- */

  total=numReturn;
  printf("Welcome to the stick game, we hope you enjoy!\n");

  while (total != 0) { 
    printf("\n-- ROUND %d  CURRENT TOTAL (%d) --\n", round, total);
    total=func_usrTurnTest(&usrTurnNow, total);
    func_showSticks(total);
    func_checkWinner(usrTurnNow, total);
    total=func_computerTurn(&usrTurnNow, total); 
    func_showSticks(total);
    func_checkWinner(usrTurnNow, total);
    round=round+1;
  }

/* END ---- MAIN TURN HANDLING ---- */

return 0;

}

 int func_showSticks (int total) {
   int i;
   for (i=0; i<total; ++i) {
     printf("|");
   }
   printf("(%d)\n\n", total);
 }

 int func_usrTurn (int *usrTurnVal, int *usrTurnTakeVal) { 
   int func_usrTurnVal, usrTake;
   char func_usrTurnTemp[120], usrTakeTemp[120];

    printf("How many sticks would you like to take away from the pile? Please enter 1, 2, or 3\n");
    fgets(func_usrTurnTemp, 120, stdin);
    func_usrTurnVal=sscanf(func_usrTurnTemp, "%d%s", &usrTake, usrTakeTemp);

    while (func_usrTurnVal != 1) {
    printf("Invalid Entry.\n"); 
    printf("How many sticks would you like to take away from the pile? Please enter 1, 2, or 3\n");
    fgets(func_usrTurnTemp, 120, stdin);
    func_usrTurnVal=sscanf(func_usrTurnTemp, "%d%s", &usrTake, usrTakeTemp);
    }

    *usrTurnTakeVal=usrTake;
    *usrTurnVal=func_usrTurnVal;

    return 0;
 }

 int func_usrTurnTest (int *usrTurnNow, int total) {
   int func_usrTake, func_usrTurnTotal;
   int usrTurnVal, usrTurnTakeVal;
   char func_usrTurnTemp[120], usrTakeTemp[120];

    func_usrTurn(&usrTurnVal, &usrTurnTakeVal);
    *usrTurnNow=1;

  while (usrTurnTakeVal < 1 || usrTurnTakeVal > 3) {
    printf("Invalid Entry\n");
    func_usrTurn(&usrTurnVal, &usrTurnTakeVal);
  }   

    printf("\nYou take: (%d) stick(s)\n", usrTurnTakeVal);

    total= total-usrTurnTakeVal;  

    printf("the new total is (%d) sticks\n", total);
    return total;
 }
 

 int func_usrInput_howMany () {
   int func_usrInput_num, func_usrInput_returnVal;
   char func_usrInput_temp[120], func_usrInputTemp[120];

   printf("How many sticks would you like to play with?\nPlease enter an integer value of 10 or more: ");
   fgets(func_usrInput_temp, 120, stdin);
   func_usrInput_returnVal=sscanf(func_usrInput_temp, "%d%s", &func_usrInput_num, func_usrInputTemp);

   while (func_usrInput_returnVal != 1) {   //  if user enters an invalid entry, prompt again till they enter a valid integer
     printf("Invalid Entry\nGOODBYE\n");
     exit(0);
//     printf("How many sticks would you like to play with?\nPlease enter an integer value of 10 or more: ");
//     fgets(func_usrInput_temp, 120, stdin);
//     func_usrInput_returnVal=sscanf(func_usrInput_temp, "%d%s", &func_usrInput_num, func_usrInputTemp);
    
     if (func_usrInput_returnVal == 1 && func_usrInput_num > 9) {
       printf("You have chosen <%d> sticks to use\n", func_usrInput_num);
       break;
     }
   }
   return func_usrInput_num;
 } 

 int func_computerTurn(int *usrTurnNow, int total) {

   int compTake;
   *usrTurnNow=0;
   compTake=total%4;

   if (compTake != 0) {
     printf("Computer takes: (%d) sticks\n", compTake);
     total=total-compTake;
   }
   else { 
     printf("Computer takes: (1) stick\n");
     compTake=1;
     total=total-compTake;
   }
    printf("the new total is (%d) sticks\n", total);

   return total;
 }

 void func_checkWinner(int usrTurnNow, int total) {
   if (total == 0 && usrTurnNow == 0) {
     printf("COMPUTER WINS!\n\n");
     exit(0);
   }
   if (total == 0 && usrTurnNow == 1) {
     printf("You WIN!!!!\n\n");
     exit(0);
   }
 }
