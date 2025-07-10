#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//returns 1 if cis a space or tab, else 0
int space_char(char c){
  return c == ' ' || c == '\t';
}

//returns 1 if theres no psaces
int non_space_char(char c){
  return !space_char(c) && c != '\0';
}

//finds the beggining of the next token
char *token_start(char *s){
  while(*s && space_char(*s)){
    s++;
  }
  return *s ? s : NULL; //if end of str return NULL (*s == '\0')
}

//finds end of tokens
char *token_terminator(char *token){
  while(*token && non_space_char(*token)){
    token++;
  }
  return token;
}

//counts the # of tokens in str
int count_tokens(char *s){
  int count = 0;
  for(char *p = token_start(s); p; p = token_start(token_terminator(p))) //move from token to token
    count++;
  return count;
}

//copies len chars from inSTr into new NULL str
char *copy_str(char *inStr, short len){
  char *copy = malloc(len + 1);
  if(!copy) return NULL;
  for(int i = 0; i < len; i++) copy[i] = inStr[i];
  copy[len] = '\0';
  return copy;
}

//count how many tokens are in the inStr
char **tokenize(char *s){
  int count = count_tokens(s);
  char **tokens = malloc((count + 1) * sizeof(char*));
  if(!tokens) return NULL;
  //iterate over the string
  char *p = token_start(s);
  for(int i = 0; i < count; i++){
    char *end = token_terminator(p);
    tokens[i] = copy_str(p, end -p);
    p = token_start(end);
  }

  tokens[count] = NULL; //finish with NULL so array can be like a list
  return tokens;
}

//loop through tokens and print its index & value
void print_tokens(char **tokens){
  for(int i = 0; tokens[i]; i++)
	printf("token[%d]: %s\n", i, tokens[i]);
}

//free ind token str then frees the array of pointers
void free_tokens(char **tokens){
  for(int i = 0; tokens[i]; i++)
    free(tokens[i]);
  free(tokens);
}
