#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char input[224];
  struct HistoryItem *history = NULL;
  int history_id = 1;

  while(1){
    printf("$ ");
    fflush(stdout);
    if(!fgets(input, sizeof(input), stdin)) break;

    input[strcspn(input, "\n")] = '\0';

    //exit out of program
    if(strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0){
      break;
    }


    if(input[0] == '!' && input[1] != '\0'){
      int id = atoi(input + 1);
      struct HistoryItem *item = recall_history(history, id);
      if(!item){
	printf("No history item found\n");
	continue;
      }
      printf("%%s", item->str);
      strncpy(input, item->str, sizeof(input));
      input[sizeof(input) - 1] = '\0';

      //print history
      if(strncmp(input, "history", 7) == 0){
	print_history(history);
	continue;
      }
    }
    //svae to history
    add_history(&history, history_id++, input); 
    char **tokens = tokenize(input); //break up input into tokens, tokenize
    print_tokens(tokens);
    free_tokens(tokens); //free up the mem
  }

  //clean up
  free_history(history);
  return 0;
}

