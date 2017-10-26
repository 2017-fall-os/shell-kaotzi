#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "stringanizer.h"


/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *getInput(void)
{
  int bufferSize = 256;
  char *buffer = malloc(sizeof(char) * bufferSize);
  int bufCount = read(0,buffer,256);	
	//printf("buffer size was %i and the letter replaced was %c", bufCount, buffer[bufCount-1]);  

buffer[bufCount-1]='\0';
return buffer;
}



///////////////////////////////////////////////////////
//this is the main. 
int main(int argc, char **argv,char **envp)
{
 
  char *input;
  char **tokens;
  int continuation=0;
  int inc;

  char **enviroment ;
  char **activeLine;
  int enviroCount=0;
  int escapeClause = 1;
  int index=0;
printf("point 1 reached\n");
  while(0<escapeClause) {
      activeLine=delimTok(envp[enviroCount],'=');
      if(activeLine){
	//printf("arg0 is%s\n", activeLine[0]);	
      	if(!compare(activeLine[0],"PATH")) {
	  printf("point 2 reached\n");	
	  enviroment=delimTok(activeLine[1],':');
	  escapeClause=0;
        }
      } else
        escapeClause=0;
      enviroCount++;
      index++;
  }

//char* test = "Help=Me=Please";

  do {
printf("point 3 reached\n");
    write(1,"$ ",2);
    input = getInput();
    //printf("address:%s\n",envp);
//printAll(enviroment);
    tokens = tokenize(input);
printf("Your enviromental variables are:\n");
printAll(enviroment);
    //status = lsh_execute(tokens);
	//inc+=1;
     //printf("\nthe value of string 1 and 2 was: %s",input);
        continuation=compare(tokens[0],"exit\0");
	//printf("the value of cont was: %i :yep..",continuation);
	//printf("\nthe first token was: %s\n",tokens[0]);
    //free(line);
    //free(args);
      
     //printf("the test phrase was:\n");
	//printAll(delimTok(test,'='));

  } while (continuation);




  return EXIT_SUCCESS;
}


