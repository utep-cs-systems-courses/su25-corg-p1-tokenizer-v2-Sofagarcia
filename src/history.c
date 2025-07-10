#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

//to add a new history item at the end of a linked list
void add_history(struct HistoryItem **head, int id, char *str){
  //to allocate memory for a nw list node
  struct HistoryItem *new_item = malloc(sizeof(struct HistoryItem));
  new_item->id = id;
  new_item->str = strdup(str); //dup the input using strdup so we can own the mem
  new_item->next = NULL;

  if(!*head){
    *head = new_item;
  }else{
    struct HistoryItem *cur = *head;
    while (cur->next){
      cur = cur->next;
    }
    cur->next = new_item;
  }
}

//prints each history item in the list
void print_history(struct HistoryItem *head){
  while(head){
    printf("%d: %s", head->id, head->str); //for each node print id and str 
    head = head->next;
  }
}

//find item by id (returns pointer with matching id)
struct HistoryItem *recall_history(struct HistoryItem *head, int id){
  while(head && head->id != id){
    head = head->next;  
  }
  return head;
}

//frees all allocated mem used by the list
void free_history(struct HistoryItem *head){
  while(head){
    struct HistoryItem *temp = head->next;
    //free the string and node itself
    free(head->str);
    free(head);
    head = temp;
  }
}

  
