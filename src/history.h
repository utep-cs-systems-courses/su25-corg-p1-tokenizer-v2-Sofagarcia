#ifndef _HISTORY_
#define _HISTORY_


struct HistoryItem {
  int id;
  char *str;
  struct HistoryItem *next;
};

//adds item to end of list
void add_history(struct HistoryItem **head, int id, char *str);

void print_history(struct HistoryItem *head);

struct HistoryItem *recall_history(struct HistoryItem *head, int id);

/*Free the history list and the strings it references. */
void free_history(struct HistoryItem *head);

#endif
