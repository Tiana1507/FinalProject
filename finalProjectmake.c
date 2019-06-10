#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "finalProjectfunc.h"

//array which will contain the initial index/executable positions
int locationarr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(int argc, char *argv[]){

  for (int i = 0; i< strlen(argv[1]); i++ )
  {
    if(!isdigit(argv[1][i])){
      printf("Please enter a number <br>\r\n");
      return 0;
    }
  }
  
  printf("Play TicTacToe with lucky num %s<br>\r\n",argv[1]);
  TicTacToe(atoi(argv[1]), locationarr);
  
  return 0;

}
