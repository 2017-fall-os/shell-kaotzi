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
  int continuation=1;
  int inc;
  int lineIndex=0;


// all the following code is used to set the enviroment variables to an array i can use. they are pulled from the envp and path is parsed and stored. 
  char **path ;
  char **activeLine;
  int enviroCount=0;
  int escapeClause = 1;
  int index=0;
  char *directCommand;
  char **parsedCommands;
 printf("point 1 reached\n");
  while(0<escapeClause) {
      activeLine=mytok(envp[enviroCount],'=');
      if(activeLine){
      	if(!compare(activeLine[0],"PATH")) {
	  printf("point 2 reached\n");	
	  path=mytok(activeLine[1],':');
	  escapeClause=0;
        }
      } else
        escapeClause=0;
      enviroCount++;
      index++;
  }


///////////////////////////////////////
// SHELL START ////////////////////////
///////////////////////////////////////
  do 
  {
    write(1,"$ ",2);
    input = getInput();
////////////logics of shell//////////////
    parsedCommands=mytok(input,' ');
    directCommand=parsedCommands[0];
    if(compare(directCommand,"exit\0"))
    {//if we aren't exiting
      if(!compare(directCommand,"cd"))
      {//if its a cd command change dir
        int rtn=chdir(parsedCommands[1]);
        if(rtn<0) perror("ERROR");
      }
      execve(directCommand,parsedCommands,path);
      int pathIndex=0;
      while(*path[pathIndex])
      {
         //printf("printIt %s\n",path[pathIndex]);
         char *tmp=joinString(path[pathIndex],"/");
         //printf("preeee %s\n",tmp);
         tmp = joinString(tmp,directCommand);
         printf("printIt %s\n",tmp);
	 //execve(tmp,parsedCommands,envp);
         //free(tmp);
         pathIndex++;
      }
    }else
    {
      continuation=0;
    }
  }while(continuation);
  return EXIT_SUCCESS;
}


