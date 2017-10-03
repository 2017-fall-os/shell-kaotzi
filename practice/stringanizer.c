#include <stdio.h>
#include <stdlib.h>
//this is header stuff
int letterCount(char *);


//this is a method to copy strings inpired by Ana Garcia
char * copyString(char *string){
    	int length = letterCount(string);
	//printf("length of string is currently set to: %i",length);
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
	//printf("\nyour table prints this: \n");fflush(stdout);
//printf(input[index]);fflush(stdout);
printf("\nyour table prints this: \n");fflush(stdout);
	while(*input[index]!='\0')
	{

	//printf("\ntable.........: ");fflush(stdout);
		printIt(input[index]);
		index++;
    	}
	//printf("this can be reached\n");
}


/*
//the main deal
int main()
{
    char string[] = "    the brown   fox jumps   \0";
    char *activeWord=copyString(string);
      
	//printIt(string);
	//printIt(activeWord);
	char **names=tokenize(string);
	printAll(names);
	//printIt(names[0]);
	//printIt(names[1]);	

    
    //printf("end found");
    return 0;
}*/
