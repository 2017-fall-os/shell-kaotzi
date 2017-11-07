#ifndef mytokIncluded  //prevent multiple inclusion
#define mytokIncluded


char * copyString(char *string);
int printIt(char *input);
int printAll(char **input);
int wordCount1(char *input);
int letterCount(char *input);
char **mytok(char *input, char delim);
char **tokenize(char *input);
int compare(char *word1, char *word2);
int makeFree(char **input);



#endif //included
