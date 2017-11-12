#include <stdio.h>
#include <stdlib.h>
#include "mytok.h"
//this is header stuff
char **tokenize(char * input);
int letterCount(char *);
char delimit = ' ';


//this is a method to copy strings inpired by Ana Garcia
char * copyString(char *string)
{
    int length = letterCount(string);
    //printf("length of string is currently set to: %i",length);
    char * copy = (char *)malloc(length+1);
    int index = 0;
    while(string[index])
    {
        copy[index] = string[index];
        index++;
        if(string[index]==delimit)
        {
            copy[index]='\0';
            return copy;//protects from accidental overwritting outside of words scope.
        }

    }
    copy[length]='\0';
    return copy;
}


//simple print command to get a full string printed to the screen
int printIt(char *input)
{
    int index =0;
    while(input[index]!='\0')
    {
        printf("%c",input[index]);
        fflush(stdout);
        index++;
    }
    printf("\n");
}

//counts the different words to be tokenized
int wordCount1(char *input)
{
    int index =0;
    int count=0;
    int words=0;
    while(input[index]!='\0')
    {
        if(input[index]==delimit)
        {
            count=0;
        }
        else
        {
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
int letterCount(char *input)
{
    int index =0;
    int count=0;
    while(input[index]!='\0')
    {
        if(input[index]==delimit)
        {
            return count;
        }
        else
        {
            count++;
        }
        index++;
    }
    return count;
}

///////////////////////////////
/////////helper class/////////
char **mytok(char * input, char delim)
{
    delimit = delim;
    return tokenize(input);
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
        if(input[index]==delimit)
        {

            count=0;
        }
        else
        {
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
//clear command
int makeFree(char **input)
{
    int index =0;
    while(*input[index]!='\0')
    {
        free(input[index]);
        index++;
    }
    free(input);
}

int printAll(char **input)
{
    int index =0;
    fflush(stdout);
    if(*input[0]=='\0')
    {
        printf("(empty)\n");
    }
    while(*input[index]!='\0')
    {
        printIt(input[index]);
        index++;
    }
}


//compare method
int compare(char* word1, char* word2)
{
    int wordLength = letterCount(word1);
    if(wordCount1(word1)!= wordCount1(word2))
        return -1;
    for(int i=0; i<wordLength; i++)
    {
        if(word2[i]=='\0')
            return -1;

        if(word1[i]!=word2[i])
            return 1;
    }
    return 0;
}



