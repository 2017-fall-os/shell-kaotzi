#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mytok.h"


/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *getInput(void)
{
  int bufferSize = 256;
  char *buffer = malloc(sizeof(char) * bufferSize);
  int bufCount = read(0,buffer,256);	
buffer[bufCount-1]='\0';
return buffer;
}



int printFormatter(char *input)
{
char **tokens = tokenize(input);
printf("tokens are:\n");
printAll(tokens);

}

///////////////////////////////////////////////////////
//this is the main. 
int main(int argc, char **argv,char **envp)
{
 
  char *input;
  char **tokens;
  int continuation=0;
  int inc;


// all the fiollowing code is used to set the enviroemnt variables to an array i can use. they are pulled from the envp and path is parsed and stored. 
  char **enviroment ;
  char **activeLine;
  int enviroCount=0;
  int escapeClause = 1;
  int index=0;
 printf("point 1 reached\n");
  while(0<escapeClause) {
      activeLine=mytok(envp[enviroCount],'=');
      if(activeLine){
      	if(!compare(activeLine[0],"PATH")) {
	  printf("point 2 reached\n");	
	  enviroment=mytok(activeLine[1],':');
	  escapeClause=0;
        }
      } else
        escapeClause=0;
      enviroCount++;
      index++;
  }


////////////////////////////////////////
// SHELL START ///////////////////////
///////////////////////////////////////
  do {
    write(1,"$ ",2);
    input = getInput();
    tokens = tokenize(input);
////////////logics of shell//////////////
    printf("tokens are:\n");
    printAll(tokens);
    printf("enviroments are:\n");
    printAll(enviroment);
    continuation=compare(tokens[0],"exit\0"); 
  } while (continuation);
  return EXIT_SUCCESS;
}


