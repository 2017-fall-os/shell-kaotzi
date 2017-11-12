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

    char **enviroment ;
    char **activeLine;
    int enviroCount=0;
////////////////////////////////////////
// TESTING AREA ///////////////////////
///////////////////////////////////////
    printf("Automated Testing");
    printFormatter("Hello my dog's name is Darwin.");
    printFormatter("   Hello  World!   ");
    printFormatter("");
    printFormatter("      ");
    printFormatter(" HelloWorld");

    do
    {
        write(1,"$ ",2);
        input = getInput();
        tokens = tokenize(input);
        printf("tokens are:\n");
        printAll(tokens);
        continuation=compare(tokens[0],"exit\0");
    }
    while (continuation);
    return EXIT_SUCCESS;
}


