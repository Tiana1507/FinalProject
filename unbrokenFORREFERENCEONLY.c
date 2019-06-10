// Original Full Working Code without using the makefile. This is all of the functions and main put into pne place.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//array which will contain the initial index/executable positions
int locationarr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//Function to display the board
int DisplayBoard(void)
{
    int intcount = 0;
    //display for loop
    for (int i = 0; i < 9; i++) {
      //checks if correct number
      if (isdigit(locationarr[i]))
      {
        intcount = intcount + 1;
        if ( (i + 1) % 3 == 0) {
          printf ("%c <br>\r\n", locationarr[i]);
        }
        else {
          printf ("%c", locationarr[i]);
        }
      }
      else {
        if ( (i + 1) % 3 == 0) {
          printf ("%c <br>\r\n", locationarr[i]);
        }
        else {
          printf ("%c", locationarr[i]);
        }
      }
    }
    return intcount;
}

//Function to check the result
int CheckResult(int intcount)
{
  int win = 0;

  //Check rows
  for (int i=0; i < 3; i++){
    if ((locationarr[0+3*i] == locationarr[1+3*i]) && (locationarr[1+3*i] == locationarr[2+3*i])) 
    {
      win = 1;
      return win;
    } 
  }
  
  //Check columns
  for (int i=0; i < 3; i++){
    if ((locationarr[0+i] == locationarr[3+i]) && (locationarr[3+i] == locationarr[6+i])) 
    {
      win = 1;
      return win;
    } 
  }

  //Check diagnal
  if ((locationarr[0] == locationarr[4]) && (locationarr[4] == locationarr[8]))
  {
    win = 1;
    return win;
  } 
  if ((locationarr[2] == locationarr[4]) && (locationarr[4] == locationarr[6]))
  {
    win = 1;
    return win;
  } 
  return win;
}


int TicTacToe(int seed) {
  
  time_t time_init = time(0);

  // 0 is false 1 is true will default when all positions are used on the board.
  //int endtrue = 0;

  //determines turn number and person going
  int turnnum = 0;

  //number to check if there are any integers
  int intcount = 0;

  //which turn's/player's respective char
  char turnchar;

  char playerinput;

  int win = 0;

  int input_int;

  printf("Init seed with user's lucky num = %d<br>\r\n",seed);
  //Set the see using user input and time
  srand(time_init + seed);

  //wincheck for loop
  while (win == 0) 
  {
    if (turnnum % 2 == 0)  
    {
      turnchar = 'X';
    }
    else 
    {
      turnchar = 'O';
    }
   
    printf ("%c's turn Turn: %d <br>\r\n", turnchar, turnnum);

    intcount = DisplayBoard();
    //printf ("intcount = %d\n",intcount);

    int valid_move = 0;
    while(valid_move == 0)
    { 
      input_int = (rand()%10 + 10)%10;
      playerinput = '1' + (input_int - 1);

      for (int i = 0; i < 9; i++) {
        if (locationarr[i] == playerinput) {
           locationarr[i] = turnchar;
           valid_move = 1;
           break;
        }
      }
    }
    printf("Computer choose %c for %c<br>\r\n",playerinput,turnchar);

    if(valid_move)
    {
      turnnum = turnnum + 1;
      intcount = DisplayBoard();
      //Check result and decide if game is over
      win = CheckResult(intcount);
      if (win){
        printf("%c Wins! Game over <br>\r\n",turnchar);
      }else{
        if(intcount == 0)
        {
          win = 2;
          printf("Game over! <br>\r\n");
        }
      }
    }
 
  }
  return 0;
}

int main(int argc, char *argv[]){

  for (int i = 0; i< strlen(argv[1]); i++ )
  {
    if(!isdigit(argv[1][i])){
      printf("Please enter a number <br>\r\n");
      return 0;
    }
  }
  
  printf("Play TicTacToe with lucky num %s<br>\r\n",argv[1]);
  TicTacToe(atoi(argv[1]));
  
  return 0;

}
