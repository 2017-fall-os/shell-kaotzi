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
	printf("buffer size was %i and the letter replaced was %c", bufCount, buffer[bufCount-1]);  

buffer[bufCount-1]='\0';
return buffer;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//tokenizer stuff
////////////////////////////////////////////////////////
int letterCount(char *);


//this is a method to copy strings inpired by Ana Garcia
char * copyString(char *string){
    	int length = letterCount(string);
	char * copy = (char *)malloc(length+1);
    	int index = 0;
    	while(string[index]){
    		copy[index] = string[index];
    		index++;
		if(string[index]==' ')
		{
			copy[index]='\0';
			return copy;//protects from accidental overwritting outside of words scope. 
		}
	
    	}
	copy[length]='\0';
	return copy;
}


//simple print command to get a full string printed to the screen
int printIt(char *input){
 	int index =0;
	while(input[index]!='\0')
	{
		printf("%c",input[index]);fflush(stdout);
		index++;
    	}
	printf("\n");
}

//counts the different words to be tokenized
int wordCount1(char *input){
	int index =0;
 	int count=0;
 	int words=0;
	while(input[index]!='\0')
	{
		if(input[index]==' ')
			{
				count=0;
		}else{
			if(count==0)
				{
					words++;
				}		
			count++;
		}
	index++;
    	}
	return words;
}

//this returns the count of letters used in a single word. NOTE must start with a none space symbol
int letterCount(char *input){
 	int index =0;
 	int count=0;
	while(input[index]!='\0')
	{
		if(input[index]==' ')
		{
			return count;
		}else{
			count++;
		}
	index++;
    	}
	return count;
}




///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////  TOKEN PART/////////////////////////////////////////////////////////////////////////




char **tokenize(char * input)
{
  int words = wordCount1(input);
 char **toks = (char **)malloc(sizeof(char*)*(words+1));
 
//time to fill out the array
int index =0;
 	int count=0;
 	int wordses=0;
	
	while(wordses<words)
	{
		//printf("index = %i, count = %i, wordses = %i\n",index,count,wordses);fflush(stdout);
		if(input[index]==' ')
			{
				
				count=0;
		}else{
			if(count==0)
				{
					//printf("hi");fflush(stdout);
					char *tmp= copyString(input+index);
					//printIt(tmp);					
					toks[wordses]=tmp;
					wordses++;
				}		
			count++;
		}
	index++;
    	}
	//char *nool ='\0';
	
char * end = (char *)malloc(1);
end[0]='\0';
toks[words]= end;
return toks;

}



//simple print command to get a full string printed to the screen
int printAll(char **input){
 	int index =0;
printf("\nyour table prints this: \n");fflush(stdout);
	while(*input[index]!='\0'&&input[index]!=NULL)
	{ 
		printIt(input[index]);
		index++;
    	}
}


int compare(char* word1, char* word2){
int wordLength = letterCount(word1); 
for(int i=0;i<wordLength;i++){
	if(word2[i]=='\0')
		return -1;

	if(word1[i]!=word2[i])
		return 1;
}
return 0;
}

///////////////////////////////////////////////////////
//this is the main. 
int main(int argc, char **argv,char **envp)
{
 
  char *input;
  char **tokens;
  int continuation=0;
  int inc;

  do {
    write(1,"$ ",2);
    input = getInput();
    //printf("address:%s\n",envp);
printAll(envp);
    tokens = tokenize(input);
printAll(tokens);
    //status = lsh_execute(tokens);
	inc+=1;
     printf("\nthe value of string 1 and 2 was: %s",input);
        continuation=compare(tokens[0],"exit\0");
	printf("the value of cont was: %i :yep..",continuation);
	printf("\nthe first token was: %s\n",tokens[0]);
    //free(line);
    //free(args);
  } while (continuation);




  return EXIT_SUCCESS;
}


