#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "mytok.h"


/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
//global variable for bufSize
int bufCount;

char *getInput(void)
{
  int bufferSize = 256;
  char *buffer = malloc(sizeof(char) * bufferSize);
  bufCount = read(0,buffer,256);	
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
  char *PS1 = getenv("PS1");
 //printf("point 1 reached\n");
  while(0<escapeClause) {
      activeLine=mytok(envp[enviroCount],'=');
      if(activeLine){
      	if(!compare(activeLine[0],"PATH")) {
	 // printf("point 2 reached\n");	
	  path=mytok(activeLine[1],':');
	  escapeClause=0;
        }
      } else
        escapeClause=0;
      enviroCount++;
      index++;
  }
 //printAll(path);
///////////////////////////////////////
// SHELL START ////////////////////////
///////////////////////////////////////
char** tmp1= mytok("      ls -ef", ' ');

  do 
  {
/*
this PS1 area tutored by Ricardo Alvarez. It checks if PS! has a value then uses it if it does, or sets it if it doesnt. 
*/
    if(getenv("PS1"))
    {
        PS1 = getenv("PS1");
        int promptLength = letterCount(PS1);
        write(1,PS1,promptLength);
    }else
    {
        write(1,"$ ",2);
        setenv("PS1","$ ",2);// setting PS1 to the prompt used

    }
    input = getInput();

////////////logics of shell//////////////
    parsedCommands=tokenize(input);
    directCommand=parsedCommands[0];

    //printf("reached and bufCount was ^%d^ ",bufCount);fflush(stdout);


    if((bufCount>1&&directCommand!=NULL))
    {

      if(compare(directCommand,"exit\0"))
      {//if we aren't exiting
        if(!compare(directCommand,"cd"))
        {//if its a cd command change dir
          int rtn=chdir(parsedCommands[1]);
          if(rtn==0) perror("ERROR");
        }

        int child=fork();
        if(child==0)
        {	
  
      
          execve(directCommand,&parsedCommands[1],envp);
          int pathIndex=0;

          while(path[pathIndex])
          {
            char *tmp=joinString(path[pathIndex],"/");
            tmp = joinString(tmp,directCommand);
            execve(tmp,parsedCommands,envp);
            free(tmp);
            pathIndex++;
          }
	  printf("command not found\n");fflush(stdout);
        }else{
        if(child<0)
        {
          perror("failed to fork proccess"); fflush(stdout);
        }else{
   	  wait(NULL);
        }///
      }
    }else
    {
      continuation=0;
    }
  }
   
  }while(continuation);
  return EXIT_SUCCESS;
}


