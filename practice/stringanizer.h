#ifndef stringanizerIncluded  //prevent multiple inclusion
#define stringanizerIncluded


char * copyString(char *string);
int printIt(char *input);
int printAll(char **input);
int wordCount1(char *input);
int letterCount(char *input);
char **delimTok(char *input, char delim);
char **tokenize(char *input);
int compare(char *word1, char *word2);



#endif //included
